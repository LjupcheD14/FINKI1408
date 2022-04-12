#include<iostream>
#include<cstring>

using namespace std;

enum Tip {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip tipp;
    float golemina;

    void copy(const OperativenSistem &o) {
        this->ime = new char[strlen(o.ime) + 1];
        strcpy(this->ime, o.ime);
        this->verzija = o.verzija;
        this->golemina = o.golemina;
        this->tipp = o.tipp;
    }

public:
    OperativenSistem(){
        this->verzija=0.0;
        this->golemina=0.0;
    }

    OperativenSistem(char *ime, float verzija, Tip tipp, float golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->golemina = golemina;
        this->tipp = tipp;
    }

    OperativenSistem(const OperativenSistem &o) {
        copy(o);
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    OperativenSistem &operator=(const OperativenSistem &o) {
        if (this != &o) {
            delete[] ime;
            copy(o);
        }
        return *this;
    }

    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << tipp << " Golemina:" << golemina <<"GB"<<endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        if (!strcmp(this->ime, os.ime)) {
            return false;
        }
        if (this->verzija != os.verzija) {
            return false;
        }
        if (this->tipp != os.tipp) {
            return false;
        }
        if (this->golemina != os.golemina) {
            return false;
        }
        return true;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (this->verzija == os.verzija) {
            return 0;
        } else if (this->verzija < os.verzija) {
            return -1;
        } else {
            return 1;
        }
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        return !strcmp(this->ime, sporedba.ime) && this->tipp == sporedba.tipp;
    }
};

class Repozitorium {
    char ime[20];
    OperativenSistem *sistemi;
    int broj;
public:
    Repozitorium(const char *ime) {
        strcpy(this->ime, ime);
        broj = 0;
    }

    ~Repozitorium() {
        delete[] sistemi;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << ime << endl;
        for (int i = 0; i < broj; i++) {
            sistemi[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem) {
        int deleteNum = broj;
        for (int i = 0; i < broj; i++) {
            if (sistemi[i].ednakviSe(operativenSistem)) {
                deleteNum = i;
            }
        }
        if (deleteNum == broj) {
            return;
        }
        if (deleteNum = broj - 1) {
            broj--;
        } else {
            for (int i = deleteNum; i < broj; i++) {
                sistemi[i] = sistemi[i + 1];
            }
            broj--;
        }
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i = 0; i < broj; i++) {
            if (sistemi[i].istaFamilija(nov) && sistemi[i].sporediVerzija(nov) == -1) {
                sistemi[i] = nov;
                return;
            }
        }
        OperativenSistem *novi = new OperativenSistem[broj + 1];
        for (int i = 0; i < broj; i++) {
            novi[i] = sistemi[i];
        }
        novi[broj] = nov;
        sistemi = novi;
        broj++;
    }





//    Repozitorium(char *ime, OperativenSistem sistemi, int broj) {
//        strcpy(this->ime, ime);
//        this->sistemi = new OperativenSistem[strlen(broj) + 1];
//        for (int i = 0; i < broj; i++) {
//            this->sistemi[i] = sistemi[i];
//        }
//        this->broj = broj;
//    }

};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
