#include <iostream>
#include <cstring>

using namespace std;

class Kvadrat{
protected:
    double dolzina;
public:
    Kvadrat(double dolzina=0){
        this->dolzina=dolzina;
    }
    Kvadrat(const Kvadrat & k){
        this->dolzina=k.dolzina;
    }
    double perimetar(){
        return dolzina*4;
    }
    double plostina(){
        return dolzina*dolzina;
    }
    void pecati(){
        cout<<"Kvadrat so dolzina a="<<dolzina<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
    }
};

class Pravoagolnik : public Kvadrat{
private:
    double x;
    double y;
public:
    Pravoagolnik(double a=0, double x=0, double y=0) : Kvadrat(a){
        this->x=x;
        this->y=y;
    }
    Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k){
        this->x=x;
        this->y=y;
    }
    double perimetar(){
        if(x==y){
            dolzina=dolzina+x;
            return Kvadrat::perimetar();
        } else {
            return (2*(dolzina+x) + 2*(dolzina+y));
        }
    }
    double plostina(){
        if(x==y){
            dolzina=dolzina+x;
            return Kvadrat::plostina();
        } else {
            return ((dolzina+x)*(dolzina+y));
        }
    }
    void pecati(){
        if(x==y){
            dolzina=dolzina+x;
            Kvadrat::pecati();
        } else {
            cout<<"Pravoagolnik so strani: "<<dolzina+x<<" i "<<dolzina+y<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl;
        }
    }
};

int main() {
	int n;
    double a,x,y;
	Kvadrat * kvadrati;
	Pravoagolnik * pravoagolnici;
	
	cin>>n;
    
    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];
    
	for (int i=0;i<n;i++){
		cin>>a;
        
		kvadrati[i] = Kvadrat(a);
	}
	
	for (int i=0;i<n;i++){
		cin>>x>>y;
        
		pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
	}
	
	int testCase;
	cin>>testCase;
    
	if (testCase==1){
		cout<<"===Testiranje na klasata Kvadrat==="<<endl;
		for (int i=0;i<n;i++)
			kvadrati[i].pecati();
	}
	else {
		cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
		for (int i=0;i<n;i++)
			pravoagolnici[i].pecati();
	}
}
