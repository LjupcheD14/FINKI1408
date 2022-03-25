#include <iostream>
#include <cstring>
#include <cmath>

#define size 3

using namespace std;

class Potpisuvac
{
private:
    char ime[20];
    char prezime[20];
    char embg[14];
public:
    Potpisuvac(){};
    Potpisuvac(char * _ime, char * _prezime, char * _embg){
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        strcpy(embg, _embg);
    }
    Potpisuvac(const Potpisuvac & p){
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
        strcpy(embg, p.embg);
    }

//    char * getEmbg(){
//        return embg;
//    }
    friend class Dogovor;
    //vasiot kod ovde
};
class Dogovor
{
private:
    int broj;
    char kategorija[50];
    Potpisuvac potpisuvaci[size];
public:
    Dogovor(){};
    Dogovor(int _broj, char * _kategorija, Potpisuvac *p){
        broj = _broj;
        strcpy(kategorija, _kategorija);
        for(int i=0; i<size; i++){
            potpisuvaci[i] = p[i];
        }
    }
    ~Dogovor(){}

    bool proverka(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(strcmp(potpisuvaci[i].embg, potpisuvaci[j].embg) == 0 && i!=j){
                    return true;
                }
            }
        } return false;
    }
    //vasiot kod ovde
};


//ne smee da se menuva main funkcijata
int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1; p[1] = p2; p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
        if(d.proverka() == true)
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}
