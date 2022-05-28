#include <iostream>
#include <cstring>

using namespace std;

class Koncert
{
private:
    char naziv[20];
    char lokacija[20];
    static double popust;
    double osnovna_cena;
public:
    Koncert(const char *naziv="", const char *lokacija="", double osnovna_cena=0)
    {
        strcpy(this->naziv,naziv);
        strcpy(this->lokacija,lokacija);
        this->osnovna_cena=osnovna_cena;
    }
    static void setSezonskiPopust(double broj)
    {
        popust=broj;
    }
    static double getSezonskiPopust()
    {
        return popust;
    }
    char *getNaziv()
    {
        return naziv;
    }
    virtual double cena()
    {
        return osnovna_cena*(1.0-popust);
    }
};
double Koncert::popust=0.2;

class ElektronskiKoncert : public Koncert
{
private:
    char *ime;
    double vreme;
    bool zabava;
public:
    ElektronskiKoncert(const char *naziv="", const char *lokacija="", double osnovna_cena=0, const char *ime="", double vreme=0, bool zabava=true) : Koncert(naziv,lokacija,osnovna_cena)
    {
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->vreme=vreme;
        this->zabava=zabava;
    }
    double cena()
    {
        if(vreme>5)
        {
            if(zabava==true)
            {
                return (Koncert::cena()+100);
            }
            else
            {
                return (Koncert::cena()+250);
            }
        }
        if(vreme>7)
        {
            if(zabava==true)
            {
                return (Koncert::cena()+310);
            }
            else
            {
                return (Koncert::cena()+460);
            }
        }
        if(zabava==true)
        {
            return Koncert::cena()-50;
        }
        else
        {
            return Koncert::cena()+100;
        }
    }
};

void najskapKoncert(Koncert **koncerti, int n)
{
    int counter=0;
    Koncert *najskap = koncerti[0];
    for(int i=0; i<n; i++)
    {
        ElektronskiKoncert *tmp = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
        if(tmp!=0)
        {
            counter++;
        }
        if(i!=0)
        {
            if(koncerti[i]->cena() > najskap->cena())
            {
                najskap=koncerti[i];
            }
        }
    }
    cout<<"Najskap koncert: "<<najskap->getNaziv()<<" "<<najskap->cena()<<endl;
    cout<<"Elektronski koncerti: "<<counter<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski)
{
    if(elektronski==true)
    {
        for(int i=0; i<n; i++)
        {
            ElektronskiKoncert *tmp = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
            if(tmp!=0)
            {
                if(strcmp(koncerti[i]->getNaziv(),naziv)==0)
                {
                    cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                    return true;
                }
            }

        }

    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(strcmp(koncerti[i]->getNaziv(),naziv)==0)
            {
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin>>tip;
    if (tip==1) //Koncert
    {
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
    }
    else if (tip==2) //cena - Koncert
    {
        cin>>naziv>>lokacija>>cenaBilet;
        Koncert k1(naziv,lokacija,cenaBilet);
        cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
    }
    else if (tip==3) //ElektronskiKoncert
    {
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
    }
    else if (tip==4) //cena - ElektronskiKoncert
    {
        cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
        ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
        cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
    }
    else if (tip==5)  //najskapKoncert
    {

    }
    else if (tip==6)  //prebarajKoncert
    {
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        najskapKoncert(koncerti,5);
    }
    else if (tip==7) //prebaraj
    {
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
        char naziv[100];
        bool elektronski;
        cin>>elektronski;
        if(prebarajKoncert(koncerti,5, "Area",elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

        if(prebarajKoncert(koncerti,5, "Area",!elektronski))
            cout<<"Pronajden"<<endl;
        else cout<<"Ne e pronajden"<<endl;

    }
    else if (tip==8) //smeni cena
    {
        Koncert ** koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
        koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
        koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
        koncerti[2] -> setSezonskiPopust(0.9);
        najskapKoncert(koncerti,4);
    }

    return 0;
}
