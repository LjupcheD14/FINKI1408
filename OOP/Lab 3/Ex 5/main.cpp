#include<iostream>
#include<cstring>

using namespace std;

class Rabotnik {
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik() {}

    Rabotnik(char *_ime, char *_prezime, int _plata) {
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        plata = _plata;
    }

    int getPlata() {
        return plata;
    }

    void pecati() {
        cout << ime << " " << prezime << " " << plata << endl;
    }

    friend class Fabrika;
};

class Fabrika {
    Rabotnik rabotnik[100];
    int brojVraboteni;
public:
    Fabrika() {};

    Fabrika(Rabotnik *_rabotnik, int _brojVraboteni) {
        for (int i = 0; i < _brojVraboteni; i++) {
            rabotnik[i] = _rabotnik[i];
        }
        brojVraboteni = _brojVraboteni;
    }

    void pecatiVraboteni() {
        cout << "Site vraboteni: " << endl;
        for (int i = 0; i < brojVraboteni; i++) {
            rabotnik[i].pecati();
        }
    }

    void pecatiSoPlata(int plata) {
        cout << "Vraboteni so plata povisoka od " << plata << " :" << endl;
        for (int i = 0; i < brojVraboteni; i++) {
            if (rabotnik[i].getPlata() > plata) {
                rabotnik[i].pecati();
            }
        }
    }

    int getBrojVraboteni() {
        return brojVraboteni;
    };

};


int main() {

    Rabotnik r[100];
    int n, plata, minimalna;
    char ime[30], prezime[30];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ime >> prezime >> plata;
        Rabotnik r1(ime, prezime, plata);
        r[i] = r1;
    }

    cin >> minimalna;
    Fabrika f(r, n);

    f.pecatiVraboteni();
    f.pecatiSoPlata(minimalna);

    return 0;
}
