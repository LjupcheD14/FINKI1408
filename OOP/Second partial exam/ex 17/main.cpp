#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class FudbalskaEkipa
{
protected:
    char ime_trener[100];
    int golovi[10];
public:
    FudbalskaEkipa(char *ime_trener="", int *golovi=0)
    {
        strcpy(ime_trener,ime_trener);
        for(int i=0; i<10; i++)
        {
            this->golovi[i]=golovi[i];
        }
    }

    virtual char *getImeKlub()=0;
    virtual double uspeh()=0;

    friend ostream&operator<<(ostream &out, FudbalskaEkipa &f)
    {
        out<<f.getImeKlub()<<endl;
        out<<f.ime_trener<<endl;
        out<<f.uspeh()<<endl;
        return out;
    }

    FudbalskaEkipa&operator+=(int number)
    {
        int tmp[10];
        int brojac=0;
        for(int i=1; i<10; i++)
        {
            tmp[brojac++]=golovi[i];
        }
        tmp[brojac]=number;
        for(int i=0; i<10; i++)
        {
            golovi[i]=tmp[i];
        }
    }

    bool operator > (FudbalskaEkipa &f)
    {
        return uspeh() > f.uspeh();
    }
};

class Klub : public FudbalskaEkipa
{
private:
    char ime_klub[50];
    int broj_tituli;
public:
    Klub(char *ime_trener="", int *golovi=0, char *ime_klub="", int broj_tituli=0) : FudbalskaEkipa(ime_trener,golovi)
    {
        strcpy(this->ime_klub,ime_klub);
        this->broj_tituli=broj_tituli;
    }
    double uspeh()
    {
        int total=0;
        for(int i=0; i<10; i++)
        {
            total+=golovi[i];
        }
        return (total*3)+(broj_tituli*1000);
    }
    char *getImeKlub()
    {
        return ime_klub;
    }
};
class Reprezentacija : public FudbalskaEkipa
{
private:
    char ime_drzava[50];
    int broj_nastapi;
public:
    Reprezentacija(char *ime_trener="", int *golovi=0, char *ime_drzava="", int broj_nastapi=0) : FudbalskaEkipa(ime_trener,golovi)
    {
        strcpy(this->ime_drzava,ime_drzava);
        this->broj_nastapi=broj_nastapi;
    }
    double uspeh()
    {
        int total=0;
        for(int i=0; i<10; i++)
        {
            total+=golovi[i];
        }
        return (total*3)+(broj_nastapi*50);
    }
    char *getImeKlub()
    {
        return ime_drzava;
    }
};

void najdobarTrener(FudbalskaEkipa **niza, int n)
{
    FudbalskaEkipa *najdobar = niza[0];
    for(int i=0; i<n; i++)
    {
        if(*niza[i] > *najdobar)
        {
            najdobar = niza[i];
        }
    }
    cout<<*najdobar;
}

int main()
{
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i)
    {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j)
        {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0)
        {
            ekipi[i] = new Klub(coach, goals, x, tg);
        }
        else if (type == 1)
        {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i)
    {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}
