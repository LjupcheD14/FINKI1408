#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

enum Tip{smartphone,computer};

class InvalidProductionDate
{
public:
    void message()
    {
        cout<<"Невалидна година на производство"<<endl;
    }
};
class Device{
private:
    char model[100];
    Tip t;
    static double casovi;
    int godina;
public:
    Device(const char *model="", Tip t=(Tip)0, int godina=0){
        strcpy(this->model,model);
        this->t=(Tip)t;
        this->godina=godina;
    }
    int getGodina(){
        return godina;
    }
    static void setPocetniCasovi(int number){
        casovi=number;
    }
    friend ostream&operator<<(ostream &out, const Device &d){
        out<<d.model<<endl;
        if(d.t==0){
            out<<"Mobilen ";
            if(d.godina>2015){
                out<<casovi+2<<endl;
            } else {
                out<<casovi<<endl;
            }
        } else {
            out<<"Laptop ";
            if(d.godina>2015){
                out<<casovi+4<<endl;
            } else {
                out<<casovi+2<<endl;
            }
            return out;
        }
    }
};
double Device::casovi=1;

class MobileServis{
private:
    char adresa[100];
    Device *niza;
    int broj;
public:
    MobileServis(const char *adresa=""){
        strcpy(this->adresa,adresa);
        niza = new Device[0];
        broj=0;
    }
    MobileServis&operator+=(Device &d){
        if(d.getGodina()>2019 || d.getGodina()<2000){
            throw InvalidProductionDate();
        }
        Device *tmp = new Device[broj+1];
        for(int i=0;i<broj;i++){
            tmp[i]=niza[i];
        }
        tmp[broj++]=d;
        delete[]niza;
        niza=tmp;
        return *this;
    }
    void pecatiCasovi(){
        cout<<"Ime: "<<adresa<<endl;
        for(int i=0;i<broj;i++){
            cout<<niza[i];
        }
    }
};

int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(Tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try{
                t+=tmp;
            }
            catch(InvalidProductionDate &d){
                d.message();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try{
            t+=tmp;
            }
            catch(InvalidProductionDate &d)
            {
                d.message();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try{
            t+=tmp;
            }
            catch(InvalidProductionDate &d)
            {
                d.message();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);

            try{
            t+=tmp;
            }
            catch(InvalidProductionDate &d)
            {
                d.message();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(Tip)tipDevice,godina);
            try{
            t+=tmp;
            }
            catch(InvalidProductionDate &d)
            {
                d.message();
            }
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}

