#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Vozilo
{
protected:
    double masa;
    int sirina, visina;
public:
    Vozilo(double masa=0, int sirina=0, int visina=0)
    {
        this->masa=masa;
        this->sirina=sirina;
        this->visina=visina;
    }
    virtual int vratiDnevnaCena()=0;
    double getMasa()
    {
        return masa;
    }
    int getSirina()
    {
        return sirina;
    }
    int getVisina()
    {
        return visina;
    }
};
class Avtomobil : public Vozilo
{
private:
    int br_vrati;
public:
    Avtomobil(double masa=0, int sirina=0, int visina=0, int br_vrati=0) : Vozilo(masa,sirina,visina)
    {
        this->br_vrati=br_vrati;
    }
    int vratiDnevnaCena()
    {
        if(br_vrati < 5)
        {
            return 100;
        }
        else
        {
            return 130;
        }
    }
};
class Avtobus : public Vozilo
{
private:
    int br_patnici;
public:
    Avtobus(double masa=0, int sirina=0, int visina=0, int br_patnici=0) : Vozilo(masa,sirina,visina)
    {
        this->br_patnici=br_patnici;
    }
    int vratiDnevnaCena()
    {
        return br_patnici*5;
    }
};
class Kamion : public Vozilo
{
private:
    double nosivost;
public:
    Kamion(double masa=0, int sirina=0, int visina=0, double nosivost=0) : Vozilo(masa,sirina,visina)
    {
        this->nosivost=nosivost;
    }
    int vratiDnevnaCena()
    {
        return (masa+nosivost)*0.02;
    }
    double getNosivost()
    {
        return nosivost;
    }
};

class ParkingPlac
{
private:
    Vozilo **niza;
    int broj;
    void copi(const ParkingPlac &p)
    {
        broj=p.broj;
        niza=new Vozilo*[broj];
        for(int i=0; i<broj; i++)
        {
            niza[i]=p.niza[i];
        }
    }
public:
    ParkingPlac()
    {
        niza = new Vozilo*[0];
        broj=0;
    }
    ~ParkingPlac()
    {
        delete[] niza;
    }
    ParkingPlac(const ParkingPlac &p)
    {
        copi(p);
    }
    ParkingPlac &operator=(const ParkingPlac &p)
    {
        if(this != &p)
        {
            delete[] niza;
            copi(p);
        }
        return *this;
    }
    ParkingPlac &operator+=(Vozilo *v)
    {
        Vozilo **tmp = new Vozilo*[broj+1];
        for(int i=0; i<broj; i++)
        {
            tmp[i]=niza[i];
        }
        tmp[broj++]=v;
        delete[] niza;
        niza=tmp;
        return *this;
    }
    double presmetajVkupnaMasa()
    {
        double vkupno=0;
        for(int i=0; i<broj; i++)
        {
            vkupno+=niza[i]->getMasa();
        }
        return vkupno;
    }
    int brojVozilaPoshirokiOd(int n)
    {
        int vkupno=0;
        for(int i=0; i<broj; i++)
        {
            if(niza[i]->getSirina() > n)
            {
                vkupno++;
            }
        }
        return vkupno;
    }
    void pecati()
    {
        int br_avtomobili=0, br_avtobusi=0, br_kamioni=0;
        for(int i=0; i<broj; i++)
        {
            Avtomobil *a = dynamic_cast<Avtomobil*>(niza[i]);
            if(a!=0)
            {
                br_avtomobili++;
            }
            Avtobus *ab = dynamic_cast<Avtobus*>(niza[i]);
            if(ab!=0)
            {
                br_avtobusi++;
            }
            Kamion *k = dynamic_cast<Kamion*>(niza[i]);
            if(k!=0)
            {
                br_kamioni++;
            }
        }

        cout<<"Brojot na avtomobili e "<<br_avtomobili<<", brojot na avtobusi e "<<br_avtobusi<<" i brojot na kamioni e "<<br_kamioni<<"."<<endl;
    }
    int pogolemaNosivostOd(Vozilo &v)
    {
        int cnt=0;
        for(int i=0; i<broj; i++)
        {
            Kamion *k = dynamic_cast<Kamion*>(niza[i]);
            if(k!=0)
            {
                if(k->getNosivost() > v.getMasa())
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int vratiDnevnaZarabotka()
    {
        int vkupno=0;
        for(int i=0; i<broj; i++)
        {
            vkupno+=niza[i]->vratiDnevnaCena();
        }
        return vkupno;
    }

};

int main()
{
    ParkingPlac p;

    int n;
    cin>>n;
    int shirina,visina, broj;
    float masa,nosivost;
    for (int i=0; i<n; i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            cin>>masa>>shirina>>visina>>broj;
            Avtomobil *a=new Avtomobil(masa,shirina,visina,broj);
            p+=a;
        }
        if(type==2)
        {
            cin>>masa>>shirina>>visina>>broj;
            p+=new Avtobus(masa,shirina,visina,broj);
        }
        if(type==3)
        {
            cin>>masa>>shirina>>visina>>nosivost;
            p+=new Kamion(masa,shirina,visina,nosivost);
        }
    }

    p.pecati();

    cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
    cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
    cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
    Avtomobil a(1200,4,3,5);
    cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl;


}
