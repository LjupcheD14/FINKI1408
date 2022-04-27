#include <iostream>
#include <cstring>

using namespace std;

class Ekipa{
protected:
    char ime[15];
    int broj_porazi;
    int broj_pobedi;
public:
    Ekipa(char *ime="", int broj_pobedi=0, int broj_porazi=0){
        strcpy(this->ime,ime);
        this->broj_pobedi=broj_pobedi;
        this->broj_porazi=broj_porazi;
    }
    Ekipa(const Ekipa &e){
        strcpy(this->ime,e.ime);
        this->broj_porazi=e.broj_porazi;
        this->broj_pobedi=e.broj_pobedi;
    }
    void pecati(){
        cout<<"Ime: "<<ime<<" Pobedi: "<<broj_pobedi<<" Porazi: "<<broj_porazi;
    }
};

class FudbalskaEkipa : public Ekipa{
private:
    int broj_crven;
    int broj_zolt;
    int broj_nereseni;
public:
    FudbalskaEkipa(){
        broj_crven=0;
        broj_zolt=0;
        broj_nereseni=0;
    }
    FudbalskaEkipa(char *ime, int broj_pobedi, int broj_porazi, int broj_crven, int broj_zolt, int broj_nereseni) : Ekipa(ime,broj_pobedi,broj_porazi){
        this->broj_crven=broj_crven;
        this->broj_zolt=broj_zolt;
        this->broj_nereseni=broj_nereseni;
    }
    int vkupnoPoeni(){
        return ((broj_pobedi*3)+broj_nereseni);
    }
    void pecati(){
        Ekipa::pecati();
        cout<<" Nereseni: "<<broj_nereseni<<" Poeni: "<<vkupnoPoeni()<<endl;
    }
};

int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}
