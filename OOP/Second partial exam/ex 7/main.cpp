#include <iostream>
#include <cstring>

using namespace std;

class OutOfBoundsException
{
public:
    void message()
    {
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
    }
};

class Karticka
{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;
public:
    Karticka(char* smetka,int pin)
    {
        strcpy(this->smetka,smetka);
        this->pin=pin;
        this->povekjePin=false;
    }
    // дополниете ја класата
    bool getDopolnitelenPin()
    {
        return povekjePin;
    }
    char *getSmetka()
    {
        return smetka;
    }
    virtual int presmetajTezina()
    {
        int digits=0;
        int k=pin;
        while(k!=0)
        {
            k/=10;
            digits++;
        }
        return digits;
    }
    int tezinaProbivanje()
    {
        int digits=0;
        int k=pin;
        while(k!=0)
        {
            k/=10;
            digits++;
        }
        return digits;
    }
    friend ostream &operator<<(ostream &out, Karticka &k)
    {
        out<<k.smetka<<": "<<k.tezinaProbivanje()<<endl;
        return out;
    }
};

//вметнете го кодот за SpecijalnaKarticka
class SpecijalnaKarticka : public Karticka
{
private:
    int *dopolnitelni;
    int n;
    static int maxn;
public:
    SpecijalnaKarticka(char* smetka,int pin, int *dopolnitelni, int n) : Karticka(smetka,pin)
    {
        this->dopolnitelni=new int[n];
        for(int i=0; i<n; i++)
        {
            this->dopolnitelni[i]=dopolnitelni[i];
        }
        this->n=n;
    }
    SpecijalnaKarticka(char smetka[15], int pin) : Karticka(smetka,pin)
    {
        this->dopolnitelni=new int[0];
        this->n=0;
    }
    int tezinaProbivanje()
    {
        return Karticka::presmetajTezina()+n;
    }
    SpecijalnaKarticka &operator+=(int k)
    {
        if(n+1>maxn)
            throw OutOfBoundsException();
        int *tmp = new int[n+1];
        for(int i=0; i<n; i++)
        {
            tmp[i]=dopolnitelni[i];
        }
        delete[] dopolnitelni;
        tmp[n]=k;
        dopolnitelni=tmp;
        return *this;
    }
    int broj()
    {
        return n;
    }
    int maks()
    {
        return maxn;
    }
};

int SpecijalnaKarticka::maxn=4;

class Banka
{
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj )
    {
        strcpy(this->naziv,naziv);
        for (int i=0; i<broj; i++)
        {
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin())
            {
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
            }
            else this->karticki[i]=new Karticka(*karticki[i]);
        }
        this->broj=broj;
    }
    ~Banka()
    {
        for (int i=0; i<broj; i++) delete karticki[i];
    }

    //да се дополни класата

    static void setLIMIT(int lim)
    {
        LIMIT=lim;
    }
    void pecatiKarticki()
    {
        cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite:"<<endl;
        for(int i=0; i<broj; i++)
        {
            if(karticki[i]->presmetajTezina()<=LIMIT)
            {
                cout<<*karticki[i];
            }
        }
    }

    void dodadiDopolnitelenPin(char *smetka, int novPin)
    {
        for(int i=0; i<broj; i++)
        {
            bool flag=false;
            int index;
            if(strcmp(karticki[i]->getSmetka(),smetka)==0)
            {
                flag=true;
                index=i;
            }
            if(flag)
            {
                SpecijalnaKarticka *sk=dynamic_cast<SpecijalnaKarticka*>(karticki[index]);
                if(sk!=0)
                {
                    try
                    {
                        *sk+=novPin;
                    }
                    catch (OutOfBoundsException e)
                    {
                        throw e;
                    }
                }
            }
        }
    }

};

int Banka::LIMIT=7;


int main()
{

    Karticka **niza;
    int n,m,pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin>>n;
    niza=new Karticka*[n];
    for (int i=0; i<n; i++)
    {
        cin>>smetka;
        cin>>pin;
        cin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i]=new Karticka(smetka,pin);
        else
            niza[i]=new SpecijalnaKarticka(smetka,pin);
    }

    Banka komercijalna("Komercijalna",niza,n);
    for (int i=0; i<n; i++) delete niza[i];
    delete [] niza;
    cin>>m;
    for (int i=0; i<m; i++)
    {
        cin>>smetka>>pin;

        try
        {
            komercijalna.dodadiDopolnitelenPin(smetka,pin);
        }
        catch(OutOfBoundsException e)
        {
            e.message();
        }

    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}
