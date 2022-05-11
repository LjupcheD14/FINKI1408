#include<iostream>
#include<cstring>

using namespace std;

class ZicanInstrument {
protected:
    char ime[20];
    int br_zici;
    int osnovna_cena;
public:
    ZicanInstrument(const char *ime = "", int br_zici = 0, int osnovna_cena = 0) {
        strcpy(this->ime, ime);
        this->br_zici = br_zici;
        this->osnovna_cena = osnovna_cena;
    }

    int getBrZici() {
        return br_zici;
    }

    virtual double cena() = 0;

    friend bool operator==(ZicanInstrument *z1, ZicanInstrument &z2) {
        if (z1->getBrZici() == z2.getBrZici())
            return true;
        return false;
    }

    friend ostream &operator<<(ostream &out, ZicanInstrument *z) {
        out << z->ime << " " << z->br_zici << " " << z->osnovna_cena << endl;
        return out;
    }
};

class Mandolina : public ZicanInstrument {
private:
    char forma[20];
public:
    Mandolina(const char *ime = "", int br_zici = 0, int osnovna_cena = 0, const char *forma = "") : ZicanInstrument(ime, br_zici,
                                                                                                         osnovna_cena) {
        strcpy(this->forma, forma);
    }

    double cena() {
        if (strcmp(forma, "Neapolitan") == 0)
            return osnovna_cena + (osnovna_cena * 0.15);
        else
            return osnovna_cena;
    }

    friend ostream &operator<<(ostream &out, Mandolina *m) {
        out << m->ime << " " << m->br_zici << " " << m->cena() << " " << m->forma << endl;
        return out;
    }
};

class Violina : public ZicanInstrument {
private:
    double golemina;
public:
    Violina(const char *ime = "", int br_zici = 0, int osnovna_cena = 0, double golemina = 0) : ZicanInstrument(ime, br_zici,
                                                                                                          osnovna_cena) {
        this->golemina = golemina;
    }

    double cena() {
        if (golemina == 0.25) {
            return osnovna_cena + (osnovna_cena * 0.1);
        } else if (golemina == 1.00) {
            return osnovna_cena + (osnovna_cena * 0.2);
        } else {
            return osnovna_cena;
        }
    }

    friend ostream &operator<<(ostream &out, Violina *v) {
        out << v->ime << " " << v->br_zici << " " << v->cena() << " " << v->golemina << endl;
        return out;
    }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **niza, int n) {
    for (int i = 0; i < n; i++) {
        if (niza[i] == zi) {
            Mandolina *m = dynamic_cast<Mandolina *>(niza[i]);
            if (m != 0) {
                cout << m->cena() << endl;
            }
            Violina *v = dynamic_cast<Violina *>(niza[i]);
            if (v != 0) {
                cout << v->cena() << endl;
            }
        }
    }
}

void pecati(ZicanInstrument **niza, int n) {
    for (int i = 0; i < n; i++) {
        cout << niza[i];
    }
}

int main() {
	char ime[20];
	int brojZici;
	float cena;
	char forma[20];
	cin >> ime >> brojZici >> cena >> forma;
	Mandolina m(ime, brojZici, cena, forma);
	int n;
	cin >> n;
	ZicanInstrument **zi = new ZicanInstrument*[2 * n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina;
		cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}
	pecatiInstrumenti(m, zi, 2 * n);
	for(int i = 0; i < 2 * n; ++i) {
		delete zi[i];
	}
	delete [] zi;
	return 0;
}
