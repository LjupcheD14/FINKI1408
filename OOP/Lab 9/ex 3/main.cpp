#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class ImaMasa
{
public:
    virtual double vratiMasa() = 0;

    virtual void pecati() = 0;
};

class PaketPijalok
{
protected:
    double volumen;
    int kolicina;
    static double gustina;
    static double ambalaza;
public:
    PaketPijalok(double volumen=0, int kolicina=0)
    {
        this->volumen=volumen;
        this->kolicina=kolicina;
    }
    double vratiMasa()
    {
        return (volumen*gustina+ambalaza)*getKolicina();
    }
    void pecati()
    {
        cout<<"kolicina "<<kolicina;
    }
    int getKolicina()
    {
        return kolicina;
    }
    static double getGustina()
    {
        return gustina;
    }
    double getVolumen()
    {
        return volumen;
    }

};

double PaketPijalok::gustina=0.8;
double PaketPijalok::ambalaza=0.2;

class PaketSok : public ImaMasa, public PaketPijalok
{
private:
    bool daliGaziran;
public:
    PaketSok(double volumen=0, int kolicina=0, bool daliGaziran=false) : PaketPijalok(volumen,kolicina)
    {
        this->daliGaziran=daliGaziran;
    }

    double vratiMasa()
    {
        if(daliGaziran==true)
        {
            return PaketPijalok::vratiMasa();
        }
        else
        {
            return PaketPijalok::vratiMasa() + (0.1*PaketPijalok::getKolicina());
        }
    }

    void pecati()
    {
        cout<<"Paket sok"<<endl;
        cout<<"kolicina "<<kolicina<<", so po "<<getVolumen()*getGustina()<<" 1(dm3)"<<endl;
    }
};
class PaketVino : public ImaMasa, public PaketPijalok
{
private:
    double procentAlkohol;
public:
    PaketVino(double volumen=0, int kolicina=0, double procentAlkohol=0) : PaketPijalok(volumen,kolicina)
    {
        this->procentAlkohol=procentAlkohol;
    }
    double vratiMasa()
    {
        return PaketPijalok::vratiMasa() * (0.9+procentAlkohol);
    }
    void pecati()
    {
        cout<<"Paket vino"<<endl;
        cout<<"kolicina "<<kolicina<<", "<<procentAlkohol*100<<"% alkohol od po "<<getVolumen()*getGustina()<<" 1(dm3)"<<endl;
    }
    double getProcentAlkohol()
    {
        return procentAlkohol;
    }
};

class Kamion
{
private:
    char registracija[9];
    char vozac[50];
    ImaMasa **niza;
    int broj;
public:
    Kamion(const char *vozac="")
    {
        strcpy(this->vozac,vozac);
        strcpy(this->registracija,"");
        niza = new ImaMasa *[0];
        broj=0;
    }
    Kamion(const char *registracija="", const char *vozac="")
    {
        if((isalpha(registracija[0])!=0) && (isalpha(registracija[1])!=0) && (isalpha(registracija[6])!=0) && (isalpha(registracija[7])!=0))
        {
            strcpy(this->vozac,vozac);
            strcpy(this->registracija,registracija);
            niza=new ImaMasa*[0];
            broj=0;
        }
        else
        {
            throw 0;
        }
    }

    void registriraj(const char *registracija="")
    {
        strcpy(this->registracija,registracija);
    }
    void dodadiElement(ImaMasa *im)
    {
        ImaMasa **tmp = new ImaMasa*[broj+1];
        for(int i=0; i<broj; i++)
        {
            tmp[i]=niza[i];
        }
        tmp[broj++]=im;
        delete[]niza;
        niza=tmp;
    }

    double vratiVkupnaMasa()
    {
        double total=0;
        for(int i=0; i<broj; i++)
        {
            total+=niza[i]->vratiMasa();
        }
        return total;
    }

    void pecati()
    {
        cout<<"Kamion so registracija "<<registracija<<" i vozac "<<vozac<<" prenesuva: "<<endl;
        for(int i=0; i<broj; i++)
        {
            niza[i]->pecati();
        }
    }

    Kamion pretovar(const char *registracija, const char *vozac)
    {
        Kamion nov(registracija,vozac);
        double maxMasa=niza[0]->vratiMasa();
        int tmp=0;
        for(int i=0; i<broj; i++)
        {
            if(niza[i]->vratiMasa()>maxMasa)
            {
                maxMasa=niza[i]->vratiMasa();
                tmp=i;
            }
        }
        for(int i=0; i<broj; i++)
        {
            if(i != tmp)
            {
                nov.dodadiElement(niza[i]);
            }
        }
        return nov;
    }
};

int main()
{
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;

    cin >> reg;
    cin >> ime;
    try
    {
        Kamion A(reg,ime);
        ImaMasa **d = new ImaMasa *[5];
        cin >> vol >> kol;
        cin >> g;
        d[0] = new PaketSok(vol, kol, g);
        cin >> vol >> kol;
        cin >> proc;
        d[1] = new PaketVino(vol, kol, proc);
        cin >> vol >> kol;
        cin >> proc;
        d[2] = new PaketVino(vol, kol, proc);
        cin >> vol >> kol;
        cin >> g;
        d[3] = new PaketSok(vol, kol, g);
        cin >> vol >> kol;
        cin >> proc;
        d[4] = new PaketVino(vol, kol, proc);

        A.dodadiElement(d[0]);
        A.dodadiElement(d[1]);
        A.dodadiElement(d[2]);
        A.dodadiElement(d[3]);
        A.dodadiElement(d[4]);
        A.pecati();
        cout << "Vkupna masa: " << A.vratiVkupnaMasa() << endl;
        cin >> reg;
        cin >> ime;
        Kamion B = A.pretovar(reg, ime);
        B.pecati();
        cout << "Vkupna masa: " << B.vratiVkupnaMasa() << endl;
    }
    catch(int)
    {
        cout<<"Pogresno vnesena registracija"<<endl;
    }

}
