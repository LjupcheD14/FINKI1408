#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;

    virtual float getMasa() = 0;

    virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    Forma(const char *boja = "", int gustina = 0) {
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }

};

class Kocka : public Igrachka, public Forma {
private:
    int sirina;
    int visina;
    int dlabocina;
public:
    Kocka(const char *boja = "", int gustina = 0, int sirina = 0, int visina = 0, int dlabocina = 0) : Forma(boja,
                                                                                                             gustina) {
        this->sirina = sirina;
        this->visina = visina;
        this->dlabocina = dlabocina;
    }

    float getVolumen() {
        return visina * sirina * dlabocina;
    }

    float getMasa() {
        return gustina * getVolumen();
    }

    float getPlostina() {
        return (visina * sirina + visina * dlabocina + dlabocina * sirina)*2;
    }
};

class Topka : public Igrachka, public Forma {
private:
    int radius;
public:
    Topka(const char *boja = "", int gustina = 0, int radius = 0) : Forma(boja,
                                                                          gustina) {
        this->radius = radius;
    }

    float getVolumen() {
        return (4 / 3.0) * (3.14) * radius * radius * radius;
    }

    float getMasa() {
        return gustina * getVolumen();
    }

    float getPlostina() {
        return radius * radius * 3.14 * 4;
    }
};


int main() {
    int sirina, visina, dlabocina, radius, gustina;
    char boja[100];
    int n;
    cin >> n;
    Igrachka **kupche = new Igrachka *[n];
    int testCase;
    int vkupnaMasa = 0;
    for (int i = 0; i < n; i++) {
        cin >> testCase;
        if (testCase == 1) {
            cin >> boja >> gustina >> radius;
            kupche[i] = new Topka(boja, gustina, radius);
            vkupnaMasa += kupche[i]->getMasa();
        } else if (testCase == 2) {
            cin >> boja >> gustina >> visina >> sirina >> dlabocina;
            kupche[i] = new Kocka(boja, gustina, sirina, visina, dlabocina);
            vkupnaMasa+=kupche[i]->getMasa();
        }
    }
    cin>>boja>>gustina>>visina>>sirina>>dlabocina;
    Kocka petra(boja,gustina,visina,sirina,dlabocina);
    if(vkupnaMasa > petra.getMasa())
    {
        cout<<"DA"<<endl;
    }
    else
    {
        cout<<"NE"<<endl;
    }
    float maxVolumen=kupche[0]->getVolumen();
    float minPlostina=kupche[0]->getPlostina();
    float volumenPetra=petra.getVolumen();
    float plostinaPetra=petra.getPlostina();
    for(int i=1;i<n;i++)
    {
        if(maxVolumen < kupche[i]->getVolumen())
        {
            maxVolumen=kupche[i]->getVolumen();
        }
        if(minPlostina > kupche[i]->getPlostina())
        {
            minPlostina=kupche[i]->getPlostina();
        }
    }
    cout<<"Razlikata e: "<<fabs(maxVolumen-volumenPetra)<<endl;
    cout<<"Razlikata e: "<<fabs(minPlostina-plostinaPetra);
}
