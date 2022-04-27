#include <iostream>
#include <cstring>

using namespace std;

class Lekar{
protected:
    int faksimil;
    char ime[10];
    char prezime[10];
    double pocetna_plata;
public:
    Lekar(int faksimil=0, char *ime="", char *prezime="", double pocetna_plata=0){
        this->faksimil=faksimil;
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->pocetna_plata=pocetna_plata;
    }
    Lekar(const Lekar & l){
        this->faksimil=l.faksimil;
        strcpy(this->ime,l.ime);
        strcpy(this->prezime,l.prezime);
        this->pocetna_plata=l.pocetna_plata;
    }
    double plata(){
        return pocetna_plata;
    }
    void pecati(){
        cout<<faksimil<<": "<<ime<<" "<<prezime<<endl;
    }
    ~Lekar(){}
};

class MaticenLekar : public Lekar{
private:
    int broj;
    double *kotizacii;

    void copi(const MaticenLekar &ml){
        this->broj=ml.broj;
        this->kotizacii=new double[broj];
        for(int i=0;i<broj;i++){
            this->kotizacii[i]=ml.kotizacii[i];
        }
        strcpy(this->ime,ml.ime);
        strcpy(this->prezime,ml.prezime);
        this->pocetna_plata=ml.pocetna_plata;
        this->faksimil=ml.faksimil;
    }
public:
    MaticenLekar() : Lekar(){
        broj=0;
        kotizacii=new double[0];
    }
    MaticenLekar(int faksimil, char *ime, char *prezime, double pocetna_plata, int broj, double *kotizacii) : Lekar(faksimil,ime,prezime,pocetna_plata){
        this->broj=broj;
        this->kotizacii=new double[broj];
        for(int i=0;i<broj;i++){
            this->kotizacii[i]=kotizacii[i];
        }
    }
    MaticenLekar(const Lekar &l, int broj, double *kotizacii) : Lekar(l){
        this->broj=broj;
        this->kotizacii=new double[broj];
        for(int i=0;i<broj;i++){
            this->kotizacii[i]=kotizacii[i];
        }
    }
    MaticenLekar(const MaticenLekar &ml){
        copi(ml);
    }
    MaticenLekar &operator=(const MaticenLekar &ml){
        if(this != &ml){
            delete[] kotizacii;
            copi(ml);
            strcpy(this->ime,ml.ime);
            strcpy(this->prezime,ml.prezime);
            this->pocetna_plata=ml.pocetna_plata;
            this->faksimil=ml.faksimil;
        }
        return *this;
    }
    ~MaticenLekar(){
        delete[] kotizacii;
    }
    double Kotizacija(){
        double vkupno=0;
        for(int i=0;i<broj;i++){
            vkupno+=kotizacii[i];
        }
        return(vkupno/broj);
    }
    double getPlata(){
        return pocetna_plata + (Kotizacija() * 0.30);
    }
    void pecati(){
        Lekar::pecati();
        cout<<"Prosek na kotizacii: "<<Kotizacija()<<endl;
    }
};

int main() {
	int n;
	cin>>n;
	int pacienti;
	double kotizacii[100];
	int faksimil;
	char ime [20];
	char prezime [20];
	double osnovnaPlata;

	Lekar * lekari = new Lekar [n];
	MaticenLekar * maticni = new MaticenLekar [n];

	for (int i=0;i<n;i++){
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);
	}

	for (int i=0;i<n;i++){
		cin >> pacienti;
		for (int j=0;j<pacienti;j++){
			cin >> kotizacii[j];
		}
		maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
	}

	int testCase;
	cin>>testCase;

	if (testCase==1){
		cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){
			lekari[i].pecati();
			cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
		}
	}
	else {
		cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){
			maticni[i].pecati();
			cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
		}
	}

	delete [] lekari;
	delete [] maticni;

	return 0;
}
