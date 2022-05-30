#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

//место за вашиот код
class Delo{
private:
    char ime[50];
    int godina;
    char zemja[50];
public:
    Delo(const char *ime="", int godina=0, const char *zemja=""){
        strcpy(this->ime,ime);
        this->godina=godina;
        strcpy(this->zemja,zemja);
    }
    char *getIme(){
        return ime;
    }
    char *getZemja(){
        return zemja;
    }
    int getGodina(){
        return godina;
    }
    void setIme(const char *ime){
        strcpy(this->ime,ime);
    }
    void setZemja(const char *zemja){
        strcpy(this->zemja,zemja);
    }
    void setGodina(int godina){
        this->godina=godina;
    }
    bool operator==(const Delo &d){
        return !(strcmp(this->ime,d.ime));
    }
};
class Pretstava{
private:
    Delo delo;
    int broj;
    char data[15];
public:
    Pretstava(Delo delo=0, int broj=0, const char *data=""){
        this->delo=delo;
        this->broj=broj;
        strcpy(this->data,data);
    }
    Delo getDelo(){
        return delo;
    }
    int getBroj(){
        return broj;
    }
    char *getData(){
        return data;
    }
    virtual double cena(){
        if(delo.getGodina() > 1900){
            if(!strcmp(delo.getZemja(),"Italija")){
                return 150;
            } else if(!strcmp(delo.getZemja(),"Rusija")){
                return 200;
            } else {
                return 130;
            }
        } else if(delo.getGodina()>=1800 && delo.getGodina()<=1900){
            if(!strcmp(delo.getZemja(),"Italija")){
                return 175;
            } else if(!strcmp(delo.getZemja(),"Rusija")){
                return 225;
            } else {
                return 155;
            }
        } else {
            if(!strcmp(delo.getZemja(),"Italija")){
                return 200;
            } else if(!strcmp(delo.getZemja(),"Rusija")){
                return 250;
            } else {
                return 180;
            }
        }
    }
};
class Opera : public Pretstava{
public:
    Opera(Delo delo=0, int broj=0, const char *data="") : Pretstava(delo,broj,data){}
};
class Balet : public Pretstava{
private:
    static int dopolnitelna_cena;
public:
    Balet(Delo delo=0, int broj=0, const char *data="") : Pretstava(delo,broj,data){}

    static void setCenaBalet(int num){
        dopolnitelna_cena=num;
    }

    double cena(){
        return Pretstava::cena()+dopolnitelna_cena;
    }
};
int Balet::dopolnitelna_cena=150;

double prihod(Pretstava **niza, int n){
    int vkupno=0;
    for(int i=0;i<n;i++){
        vkupno+=niza[i]->cena() * niza[i]->getBroj();
    }
    return vkupno;
}
int brojPretstaviNaDelo (Pretstava **niza, int n, Delo d){
    int vkupno=0;
    for(int i=0;i<n;i++){
        if(niza[i]->getDelo()==d){
            vkupno++;
        }
    }
    return vkupno;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
        case 1:
            //Testiranje na klasite Opera i Balet
        {
            cout<<"======TEST CASE 1======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->getDelo().getIme()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->getDelo().getIme()<<endl;
        }break;

        case 2:
            //Testiranje na  klasite Opera i Balet so cena
        {
            cout<<"======TEST CASE 2======="<<endl;
            Pretstava* p1=readPretstava();
            cout<<p1->cena()<<endl;
            Pretstava* p2=readPretstava();
            cout<<p2->cena()<<endl;
        }break;

        case 3:
            //Testiranje na operator ==
        {
            cout<<"======TEST CASE 3======="<<endl;
            Delo f1=readDelo();
            Delo f2=readDelo();
            Delo f3=readDelo();

            if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
            if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

        }break;

        case 4:
            //testiranje na funkcijata prihod
        {
            cout<<"======TEST CASE 4======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();

            }
            cout<<prihod(pole,n);
        }break;

        case 5:
            //testiranje na prihod so izmena na cena za 3d proekcii
        {
            cout<<"======TEST CASE 5======="<<endl;
            int cenaBalet;
            cin>>cenaBalet;
            Balet::setCenaBalet(cenaBalet);
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }
            cout<<prihod(pole,n);
        }break;

        case 6:
            //testiranje na brojPretstaviNaDelo
        {
            cout<<"======TEST CASE 6======="<<endl;
            int n;
            cin>>n;
            Pretstava **pole=new Pretstava*[n];
            for (int i=0;i<n;i++){
                pole[i]=readPretstava();
            }

            Delo f=readDelo();
            cout<<brojPretstaviNaDelo(pole,n,f);
        }break;

    };
    return 0;
}
