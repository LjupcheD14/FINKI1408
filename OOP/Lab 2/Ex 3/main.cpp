#include <iostream>
#include <cstring>
using namespace std;

class Film{
private:
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;
public:
    Film(){};
    Film(char i[100], char r[50], char z[50], int g){
        strcpy(ime,i);strcpy(reziser,r);strcpy(zanr,z);godina=g;
    }
    ~Film(){};
    void print(Film *niza, int n, int god_sp){
        for(int i=0; i<n; i++){
            if(niza[i].godina == god_sp){
                cout<<"Ime: "<<niza[i].ime<<endl<<"Reziser: "<<niza[i].reziser<<endl<<"Zanr: "<<niza[i].zanr<<endl<<"Godina: "<<niza[i].godina<<endl;

            }
        }
    }
};

int main() {
	int  n;
	cin>>n;
	Film *niza = new Film[n];
	for(int i=0; i<n; i++){
        char ime[100],reziser[50],zanr[50]; int godina;
        cin>>ime>>reziser>>zanr>>godina;
        niza[i] = Film(ime,reziser,zanr,godina);
	}
	int godina; cin>>godina; niza[0].print(niza,n,godina); delete[] niza;
	return 0;
}
