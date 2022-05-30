#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class SMS{
protected:
    double osnovna_cena;
    char pret_broj[15];
    static double DANOK;
public:
    SMS(const char *pret_broj="", double osnovna_cena=0){
        this->osnovna_cena=osnovna_cena;
        strcpy(this->pret_broj,pret_broj);
    }
    virtual double SMS_cena()=0;

    friend ostream&operator<<(ostream &out, SMS &s){
        return out<<"Tel: "<<s.pret_broj<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
    }

};
double SMS::DANOK=1.18;

class RegularSMS : public SMS{
private:
    char tekst[1000];
    bool roaming;
    static double REGDANOK;
public:
    RegularSMS(const char *pret_broj="", double osnovna_cena=0, const char *tekst="", bool roaming=true) : SMS(pret_broj,osnovna_cena){
        strcpy(this->tekst,tekst);
        this->roaming=roaming;
    }
    double SMS_cena(){
        if(roaming==true){
            double total=osnovna_cena*REGDANOK;
            int dolzina=strlen(tekst)/100;
            if(dolzina==0){
                return total;
            } else {
                return total*(dolzina+1);
            }
        } else {
            double total=osnovna_cena*1.18;
            int dolzina=strlen(tekst)/160;
            if(dolzina==0){
                return total;
            } else {
                return total*(dolzina+1);
            }
        }
    }
    static void set_rProcent(double n){
        REGDANOK = (n+100)/100;
    }
};
double RegularSMS::REGDANOK=4.0;

class SpecialSMS : public SMS{
private:
    bool humanitarni;
    static double SPECDANOK;
public:
    SpecialSMS(const char *pret_broj="", double osnovna_cena=0, bool humanitarni=true) : SMS(pret_broj,osnovna_cena){
        this->humanitarni=humanitarni;
    }
    double SMS_cena(){
        if(humanitarni==false){
            return osnovna_cena*SPECDANOK;
        } else {
            return osnovna_cena;
        }
    }
    static void set_sProcent(double n){
        SPECDANOK=(n+100)/100;
    }
};
double SpecialSMS::SPECDANOK=2.5;

void vkupno_SMS(SMS **poraka, int n){
    double vkupnoREG=0,vkupnoSPEC=0;
    int brojacREG=0,brojacSPEC=0;
    for(int i=0;i<n;i++){
        SpecialSMS *tmp = dynamic_cast<SpecialSMS*>(poraka[i]);
        if(tmp!=0){
            brojacSPEC++;
            vkupnoSPEC+=tmp->SMS_cena();
        } else {
            brojacREG++;
            vkupnoREG+=poraka[i]->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<brojacREG<<" regularni SMS poraki i nivnata cena e: "<<vkupnoREG<<endl;
    cout<<"Vkupno ima "<<brojacSPEC<<" specijalni SMS poraki i nivnata cena e: "<<vkupnoSPEC<<endl;
}


int main(){

	char tel[20], msg[1000];
	float cena;
	float price;
    int p;
	bool roam, hum;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
                cin >> roam;
				
				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
    if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;	
        SMS *sms1, *sms2;	
        	cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;
        
            cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;	
        	cin >> p;
        	RegularSMS::set_rProcent(p);
        	sms2 = new RegularSMS(tel, cena, msg, roam);
        	cout << *sms2;
        
        delete sms1, sms2;
	}
    if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;	
        SMS *sms1, *sms2;	
        	cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;
        
            cin >> tel;
			cin >> cena;
			cin >> hum;	
        	cin >> p;
        	SpecialSMS::set_sProcent(p);
        	sms2 = new SpecialSMS(tel, cena, hum);
        	cout << *sms2;
        
        delete sms1, sms2;
	}
	
	return 0;
}
