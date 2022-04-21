
//pecati dobro vo clion, na courses greska -.-

#include<iostream>
#include<cstring>

using namespace std;

class PlDrustvo {
private:
    char *ime;
    int turi;
    int clenovi;

    void copi(const PlDrustvo &other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->turi = other.turi;
        this->clenovi = other.clenovi;
    }

public:
    PlDrustvo(char *ime = "", int turi = 0, int clenovi = 0) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->turi = turi;
        this->clenovi = clenovi;
    }

    PlDrustvo(int clenovi){
        this->clenovi=clenovi;
    }

    PlDrustvo(const PlDrustvo &other) {
        copi(other);
    }

    PlDrustvo &operator=(const PlDrustvo &other) {
        if (this != &other) {
            delete[] ime;
            copi(other);
        }
        return *this;
    }

    PlDrustvo operator+(PlDrustvo &other) {
        if (this->clenovi > other.clenovi) {
            PlDrustvo res(this->ime, this->turi, this->clenovi + other.clenovi);
            return res;
        }
        PlDrustvo res(other.ime, other.turi, this->clenovi + other.clenovi);
        return res;
    }

    bool operator>(PlDrustvo &other) {
        return this->clenovi > other.clenovi;
    }

    bool operator<(PlDrustvo &other) {
        return this->clenovi < other.clenovi;
    }

    friend ostream &operator<<(ostream &o, PlDrustvo &other) {
        o << "Ime: " << other.ime << " Turi: " << other.turi << " Clenovi: " << other.clenovi << endl;
        return o;
    }

    ~PlDrustvo() {
        delete[] ime;
    }

};

void najmnoguClenovi(PlDrustvo *drustva, int broj) {
    PlDrustvo max(0);
    int maksI = 0;
    for (int i = 0; i < broj; i++) {
        if (drustva[i] > max) {
            max = drustva[i];
            maksI = i;
        }
    }
    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << drustva[maksI] << endl;
}


int main() {
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i = 0; i < 3; i++) {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin >> ime;
        cin >> brTuri;
        cin >> brClenovi;
        PlDrustvo p(ime, brTuri, brClenovi);
        drustva[i] = p;

    }

    pl = drustva[0] + drustva[1];
    cout << pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
