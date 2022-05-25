#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class InvalidDateException
{
private:
    int den;
    int mesec;
    int godina;
public:
    InvalidDateException(int den,int mesec,int godina)
    {
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
    }
    void message()
    {
        cout<<"Invalid Date "<<den<<"/"<<mesec<<"/"<<godina<<endl;
    }
};
class NotSuportedCurrencyException
{
private:
    char valuta[4];
public:
    NotSuportedCurrencyException(const char *valuta)
    {
        strcpy(this->valuta,valuta);
    }
    void message()
    {

        cout<<valuta<<" is not a supported currency"<<endl;
    }
};
class Transakcija
{
protected:
    int den;
    int mesec;
    int godina;
    double iznos;
    static double EUR;
    static double USD;
public:
    Transakcija(int den=0, int mesec=0, int godina=0, double iznos=0)
    {
        if(den<1 || den>31)
        {
            throw InvalidDateException(den,mesec,godina);
        }
        else if(mesec<1 || mesec>12)
        {
            throw InvalidDateException(den,mesec,godina);
        }
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
        this->iznos=iznos;
    }
    virtual double voDenari() = 0;
    virtual double voEvra() = 0;
    virtual double voDolari() = 0;
    virtual void pecati() = 0;

    static void setUSD(double num)
    {
        USD=num;
    }
    static void setEUR(double num)
    {
        EUR=num;
    }
    static double getEUR()
    {
        return Transakcija::EUR;
    }
    static double getUSD()
    {
        return Transakcija::USD;
    }
};

double Transakcija::EUR=61;
double Transakcija::USD=50;

class DenarskaTransakcija : public Transakcija
{
public:
    DenarskaTransakcija(int den=0,int mesec=0,int godina=0,double iznos=0) : Transakcija(den,mesec,godina,iznos)
    {

    }
    double voDenari()
    {
        return iznos;
    }
    double voEvra()
    {
        return iznos/Transakcija::EUR;
    }
    double voDolari()
    {
        return iznos/Transakcija::USD;
    }
    void pecati()
    {
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" MKD"<<endl;
    }
};

class DeviznaTransakcija : public Transakcija
{
private:
    char valuta[4];
public:
    DeviznaTransakcija(int den=0,int mesec=0,int godina=0,double iznos=0,const char *valuta="") : Transakcija(den,mesec,godina,iznos)
    {
        if(strcmp(valuta,"EUR")!=0 && strcmp(valuta,"USD")!=0)
        {
            throw NotSuportedCurrencyException(valuta);
        }
        strcpy(this->valuta,valuta);
    }
    double voDenari()
    {
        if(strcmp(valuta,"EUR")==0)
        {
            return 1.0*iznos*Transakcija::EUR;
        }
        else
        {
            return 1.0*iznos*Transakcija::USD;
        }
    }
    double voEvra()
    {
        if(strcmp(valuta,"EUR") == 0)
        {
            return 1.0*iznos;
        }
        else
        {
            return (iznos*Transakcija::USD*1.0)/Transakcija::EUR;
        }
    }
    double voDolari()
    {
        if(strcmp(valuta,"USD") == 0)
        {
            return 1.0*iznos;
        }
        else
        {
            return(1.0*iznos*Transakcija::EUR)/Transakcija::USD;
        }
    }
    void pecati()
    {
        cout<<den<<"/"<<mesec<<"/"<<godina<<" "<<iznos<<" "<<valuta<<endl;
    }
};

class Smetka
{
private:
    Transakcija **niza;
    int broj;
    char brojSmetka[15];
    double pocetnoSaldo;
    void copy(const Smetka &s)
    {
        broj=s.broj;
        niza=new Transakcija*[broj];
        for(int i=0; i<broj; i++)
        {
            niza[i]=s.niza[i];
        }
        strcpy(brojSmetka,s.brojSmetka);
        pocetnoSaldo=s.pocetnoSaldo;
    }
public:
    Smetka(const char *brojSmetka="", double pocetnoSaldo=0)
    {
        niza=new Transakcija*[0];
        broj=0;
        strcpy(this->brojSmetka, brojSmetka);
        this->pocetnoSaldo=pocetnoSaldo;
    }
    Smetka(const Smetka &s)
    {
        copy(s);
    }
    Smetka&operator=(const Smetka &s)
    {
        if(this != &s)
        {
            delete[] niza;
            copy(s);
        }
        return *this;
    }
    ~Smetka()
    {
        delete[] niza;
    }
    Smetka &operator +=(Transakcija *t)
    {
        Transakcija **tmp=new Transakcija*[broj+1];
        for(int i=0; i<broj; i++)
        {
            tmp[i]=niza[i];
        }
        tmp[broj++]=t;
        delete[] niza;
        niza=tmp;
        return *this;
    }
    double vkupnoSaldo()
    {
        double vkupno=pocetnoSaldo;
        for(int i=0; i<broj; i++)
        {
            vkupno+=niza[i]->voDenari();
        }
        return vkupno;
    }
    void izvestajVoDenari()
    {
        double vkupno=vkupnoSaldo();
        cout<<"Korisnikot so smetka: "<<brojSmetka<<" ima momentalno saldo od "<<vkupno<<" MKD"<<endl;
    }
    void izvestajVoEvra()
    {
        double vkupno=vkupnoSaldo()/Transakcija::getEUR();
        cout<<"Korisnikot so smetka: "<<brojSmetka<<" ima momentalno saldo od "<<vkupno<<" EUR"<<endl;
    }
    void izvestajVoDolari()
    {
        double vkupno=vkupnoSaldo()/Transakcija::getUSD();
        cout<<"Korisnikot so smetka: "<<brojSmetka<<" ima momentalno saldo od "<<vkupno<<" USD"<<endl;
    }
    void pecatiTransakcii()
    {
        for(int i=0; i<broj; i++)
        {
            niza[i]->pecati();
        }
    }
};

int main ()
{

    Smetka s ("300047024112789",1500);

    int n, den, mesec, godina, tip;
    double iznos;
    char valuta [3];

    cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>tip>>den>>mesec>>godina>>iznos;
        if (tip==2)
        {
            cin>>valuta;
            try
            {
                Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);
                s+=t;
            }
            catch(NotSuportedCurrencyException &n)
            {
                n.message();
            }
            catch(InvalidDateException &d)
            {
                d.message();
            }

            //delete t;
        }
        else
        {
            try
            {
                Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);
                s+=t;
            }
            catch(InvalidDateException &d)
            {
                d.message();
            }

            //delete t;
        }

    }
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



    return 0;
}
