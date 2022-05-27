#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Vozac
{
protected:
    char ime[100];
    int vozrast;
    int broj_trki;
    bool veteran;
public:
    Vozac(char ime[100], int vozrast, int broj_trki, bool veteran)
    {
        strcpy(this->ime,ime);
        this->vozrast=vozrast;
        this->broj_trki=broj_trki;
        this->veteran=veteran;
    }
    virtual double zarabotuvacka()=0;
    virtual double danok()=0;
    friend ostream &operator<<(ostream &out, Vozac &v)
    {
        out<<v.ime<<endl<<v.vozrast<<endl<<v.broj_trki<<endl;
        if(v.veteran) out<<"VETERAN"<<endl;
        return out;
    }
    bool operator==(Vozac &v)
    {
        return this->zarabotuvacka()==v.zarabotuvacka();
    }

};
class Avtomobilist : public Vozac
{
private:
    double cena;
public:
    Avtomobilist(char ime[100], int vozrast, int broj_trki, bool veteran, double cena) : Vozac(ime,vozrast,broj_trki,veteran)
    {
        this->cena=cena;
    }
    double zarabotuvacka()
    {
        return cena/5;
    }
    double danok()
    {
        if(broj_trki>10)
        {
            return zarabotuvacka()*0.15;
        }
        else
        {
            return zarabotuvacka()*0.10;
        }
    }
};

class Motociklist : public Vozac
{
private:
    int moknost;
public:
    Motociklist(char ime[100], int vozrast, int broj_trki, bool veteran, int moknost) : Vozac(ime,vozrast,broj_trki,veteran)
    {
        this->moknost=moknost;
    }
    double zarabotuvacka()
    {
        return moknost * 20;
    }
    double danok()
    {
        if(veteran==true)
        {
            return zarabotuvacka()*0.25;
        }
        else
        {
            return zarabotuvacka()*0.2;
        }
    }
};

int soIstaZarabotuvachka(Vozac **niza, int n, Vozac *v)
{
    int broj=0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->zarabotuvacka()==v->zarabotuvacka())
        {
            broj++;
        }
    }
    return broj;
}

int main()
{
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i)
    {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x)
        {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        }
        else
        {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i)
    {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}
