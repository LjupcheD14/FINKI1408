#include<iostream>
#include<cstring>

using namespace std;

class Automobile {
private:
private:
    char *marka;
    int *registracija;
    int brzina;
public:
    Automobile() {
        this->registracija = new int[5];
        brzina = 0;
    }

    Automobile(char *marka, int *registracija, int brzina) {
        this->marka = new char[strlen(marka) + 1];
        strcpy(this->marka, marka);
        this->registracija = new int[5];
        for (int i = 0; i < 5; i++) {
            this->registracija[i] = registracija[i];
        }
        this->brzina = brzina;
    }

    bool operator==(const Automobile &am) {
        for (int i = 0; i < 5; i++) {
            if (registracija[i] != am.registracija[i]) {
                return false;
            }
        }
        return true;
    }

    friend ostream &operator<<(ostream &out, Automobile &am) {
        out << "Marka\t" << am.marka << "\tRegistracija[ ";
        for (int i = 0; i < 5; i++) {
            out << am.registracija[i] << " ";
        }
        out << "]" << endl;
        return out;
    }

    int getBrzima() {
        return brzina;
    }
};

class RentACar {
private:
    char ime[100];
    Automobile *autos;
    int broj;
public:
    RentACar(const char ime[]) {
        strcpy(this->ime, ime);
        this->broj = 0;
    }

    RentACar &operator+=(Automobile avto) {
        Automobile *tmp = new Automobile[broj + 1];
        for (int i = 0; i < broj; i++) {
            tmp[i] = autos[i];
        }
        if (broj) delete[] autos;
        tmp[broj] = avto;
        broj++;
        autos = tmp;
        return *this;
    }

    RentACar &operator-=(Automobile &avto) {
        int deleteIndex = broj;
        for (int i = 0; i < broj; i++) {
            if (autos[i] == avto)
                deleteIndex = i;
        }
        if (deleteIndex == broj)
            return *this;
        for (int i = deleteIndex; i < broj - 1; i++) {
            autos[i] = autos[i + 1];
        }
        broj--;
        return *this;
    }

    void pecatiNadBrzina(int max) {
        cout << ime << endl;
        for (int i = 0; i < broj; i++) {
            if (autos[i].getBrzima() > max)
                cout << autos[i];
        }
    }
};

int main() {
    RentACar agencija("FINKI-Car");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char marka[100];
        int regisracija[5];
        int maximumBrzina;

        cin >> marka;

        for (int i = 0; i < 5; i++)
            cin >> regisracija[i];

        cin >> maximumBrzina;

        Automobile nov = Automobile(marka, regisracija, maximumBrzina);

        //dodavanje na avtomobil
        agencija += nov;

    }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin >> marka;
    for (int i = 0; i < 5; i++)
        cin >> regisracija[i];
    cin >> maximumBrzina;

    Automobile greshka = Automobile(marka, regisracija, maximumBrzina);

    //brishenje na avtomobil
    agencija -= greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}
