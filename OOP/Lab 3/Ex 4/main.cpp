#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

//vasiot kod ovde
class Masa {
private:
    int dolzina;
    int sirina;
public:
    Masa() {};

    Masa(int _dolzina, int _sirina) {
        dolzina = _dolzina;
        sirina = _sirina;
    }
    //~Masa();

    void pecati() {
        cout << "Masa: " << dolzina << " " << sirina<<endl;
    }
};

class Soba {
private:
    Masa masa;
    int dolzina;
    int sirina;
public:
    Soba() {}

    Soba(int _dolzina, int _sirina, Masa _masa) {
        masa = _masa;
        dolzina = _dolzina;
        sirina = _sirina;
    }
//    ~Soba();

    void pecati() {
        cout << "Soba: " << dolzina << " " << sirina << " ";
        masa.pecati();
    }
};

class Kukja{
private:
    Soba soba;
    char adresa[50];
public:
    Kukja(){};
    Kukja(Soba _soba, char * _adresa){
        soba = _soba;
        strcpy(adresa, _adresa);
    }
//    ~Kukja();
    void pecati(){
        cout<<"Adresa: "<<adresa<<" ";
        soba.pecati();
    }
};

//ne smee da se menuva main funkcijata!
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
        Masa m(masaSirina,masaDolzina);
        int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
        Soba s(sobaSirina,sobaDolzina,m);
        char adresa[30];
        cin>>adresa;
        Kukja k(s,adresa);
        k.pecati();
    }

    return 0;
}
