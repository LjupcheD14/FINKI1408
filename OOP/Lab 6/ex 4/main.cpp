#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina{
protected:
    char *adresa;
    int kvadratura;
    int cena;
    void copi(const Nedviznina &n){
        this->adresa = new char[strlen(n.adresa)+1];
        strcpy(this->adresa,n.adresa);
        this->kvadratura=n.kvadratura;
        this->cena=n.cena;
    }
public:
    Nedviznina()
    {
        adresa=new char[0];
        kvadratura=0;
        cena=0;
    }

    Nedviznina(char *adresa, int kvadratura, int cena){
        this->adresa = new char[strlen(adresa)+1];
        strcpy(this->adresa,adresa);
        this->kvadratura=kvadratura;
        this->cena=cena;
    }
    Nedviznina(const Nedviznina &n){
        copi(n);
    }
    Nedviznina &operator=(const Nedviznina &n){
        if(this != &n){
            delete[] adresa;
            copi(n);
        }
        return *this;
    }
    ~Nedviznina(){
        delete[] adresa;
    }
    double vkupnaCena(){
        return kvadratura*cena;
    }
    double danokNaImot(){
        return cena*0.05;
    }
    void pecati(){
        cout<<adresa<<", "<<"Kvadratura: "<<kvadratura<<", Cena po Kvadrat: "<<cena<<endl;
    }
    friend istream &operator>>(istream &in, Nedviznina &n){
        in>>n.adresa>>n.kvadratura>>n.cena;
        return in;
    }
    char *getAdresa(){
        return adresa;
    }
};

class Vila : public Nedviznina{
private:
    int danokNaLuksuz;
public:
    void pecati(){
        cout<<adresa<<", Kvadratura: "<<kvadratura<<", Cena po Kvadrat: "<<cena<<", Danok na luksuz: "<<danokNaLuksuz<<endl;
    }
    double danokNaImot(){
        //return (vkupnaCena()*((danokNaLuksuz+5)/100.0));
        return (vkupnaCena() * ((danokNaLuksuz+5)/100.0));
    }
    char *getAdresa(){
        return adresa;
    }
    friend istream &operator>>(istream &in, Vila &v){
        in>>v.adresa>>v.kvadratura>>v.cena>>v.danokNaLuksuz;
        return in;
    }
};

int main(){
    Nedviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}
