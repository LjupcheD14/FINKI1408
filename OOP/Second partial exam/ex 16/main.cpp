#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


class Transport
{
protected:
    char destinacija[50];
    int osnovna_cena;
    int rastojanie;
public:
    Transport(char *destinacija="", int osnovna_cena=0, int rastojanie=0)
    {
        strcpy(this->destinacija,destinacija);
        this->osnovna_cena=osnovna_cena;
        this->rastojanie=rastojanie;
    }
    virtual double cena()=0;

    bool operator <(Transport &t)
    {
        return rastojanie < t.rastojanie;
    }
    friend ostream&operator<<(ostream &out, Transport &t)
    {
        return out<<t.destinacija<<" "<<t.rastojanie<<" "<<t.cena()<<endl;
    }
};
class AvtomobilTransport : public Transport
{
private:
    bool sofer;
public:
    AvtomobilTransport(char *destinacija="", int osnovna_cena=0, int rastojanie=0, bool sofer=false):Transport(destinacija,osnovna_cena,rastojanie)
    {
        this->sofer=sofer;
    }
    double cena()
    {
        if(sofer==true)
        {
            return osnovna_cena*1.2;
        }
        else
        {
            return osnovna_cena;
        }
    }
};
class KombeTransport : public Transport
{
private:
    int lugje;
public:
    KombeTransport(char *destinacija="", int osnovna_cena=0, int rastojanie=0, int lugje=0):Transport(destinacija,osnovna_cena,rastojanie)
    {
        this->lugje=lugje;
    }
    double cena()
    {
        return osnovna_cena-(lugje*200);
    }
};

void pecatiPoloshiPonudi (Transport **ponudi, int n, Transport &t)
{
    Transport *tmp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ponudi[i]->cena() > ponudi[j]->cena())
            {
                tmp=ponudi[i];
                ponudi[i]=ponudi[j];
                ponudi[j]=tmp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(ponudi[i]->cena() > t.cena())
        {
            cout<<*ponudi[i];
        }
    }
}

int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
