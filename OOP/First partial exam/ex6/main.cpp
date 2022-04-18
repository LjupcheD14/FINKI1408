#include<iostream>
#include <cstring>
using namespace std;

struct Voz{
    char relacija[50];
    double km;
    int patnici;
};

struct ZeleznickaStanica{
    char grad[20];
    Voz vozovi[30];
    int broj;
};

void najkratkaRelacija(ZeleznickaStanica * zs, int n, char *grad){
    for(int i=0;i<n;i++){
        if(!strcmp(zs[i].grad,grad)){
            int najmal=0;
            double najmalkuKM = zs[i].vozovi[0].km;
            for(int j=0;j<zs[i].broj;j++){
                if(zs[i].vozovi[j].km<=najmalkuKM){
                    najmalkuKM = zs[i].vozovi[j].km;
                    najmal = j;
                }
            }
            cout<<"Najkratka relacija: "<<zs[i].vozovi[najmal].relacija<<" ("<<zs[i].vozovi[najmal].km<<" km)"<<endl;
            return;
        }
    }
}

int main(){

    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){

    char grad[20];
    int k;
    cin>>grad;
    strcpy(zStanica[i].grad, grad);
    cin>>k;
    zStanica[i].broj=k;
    for(int j=0;j<k;j++){
        char rel[50];
        double km;
        int pat;
        cin>>rel>>km>>pat;
        strcpy(zStanica[i].vozovi[j].relacija,rel);
        zStanica[i].vozovi[j].km=km;
        zStanica[i].vozovi[j].patnici=pat;
    }
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
    }

    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
