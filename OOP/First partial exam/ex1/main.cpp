#include <iostream>
#include <cstring>


enum tip {pop,rap,rok};
class Pesna{
    private:
        char *ime;
        int vreme;
        tip tipPesna;
    public:
        Pesna(){
            // default
        }
        Pesna(char *ime, int vreme, tip tipPesna){
            this->ime = new char[strlen(ime)+1];
            strcpy(this->ime,ime);
            this->vreme=vreme;
            this->tipPesna=tipPesna;
        }
        int getVreme(){return this->vreme;}
        tip getTip(){return this->tipPesna;}
        void pecati(){
            std::cout<<"\""<<ime<<"\"-"<<vreme<<"min"<<std::endl;
        }
};
class CD{
    private:
        Pesna pesni[10];
        int brojPesni;
        int maksVreme;
    public:
        CD(){
            // default
        }
        CD(Pesna pesni[10],int brojPesni,int maksVreme){
            for(int i=0;i>brojPesni;i++){
                this->pesni[i] = pesni[i];
            }
            this->brojPesni=brojPesni;
            this->maksVreme=maksVreme;
        }
        CD(int maksVreme){
            this->brojPesni=0;
            this->maksVreme=maksVreme;
        }
        void dodadiPesna(Pesna p){
            int vkupnoVreme = 0;
            for(int i =0;i<this->brojPesni;i++){
                vkupnoVreme+=this->pesni[i].getVreme();
            }
            if(this->brojPesni<10 && vkupnoVreme+p.getVreme()<this->maksVreme){
                this->pesni[brojPesni] = p;
                this->brojPesni++;
            }
        }
        void pecatiPesniPoTip(tip t){
            for(int i=0;i<this->brojPesni;i++){
                if((tip)this->pesni[i].getTip()==(tip)t) this->pesni[i].pecati();
            }
        }
        Pesna getPesna(int id){
            return this->pesni[id];
        }
        int getBroj(){
            return this->brojPesni;
        }
};

using namespace std;

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======";
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======";
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======";
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}
