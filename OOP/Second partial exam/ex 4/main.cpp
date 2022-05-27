#include <iostream>
#include <cstring>
#include <cmath>
#include <string.h>

using namespace std;

enum Golemina{
    mala,golema,familijarna
};

class Pizza{
protected:
    char ime[20];
    char sostojki[100];
    double osnovna_cena;
public:
    Pizza(char ime[20], char sostojki[100], double osnovna_cena){
        strcpy(this->ime,ime);
        strcpy(this->sostojki,sostojki);
        this->osnovna_cena=osnovna_cena;
    }
    virtual double price()=0;

    bool operator<(Pizza &p){
        return this->price() < p.price();
    }

};

class FlatPizza : public Pizza{
private:
    Golemina golemina;
public:
    FlatPizza(char ime[20], char sostojki[100], double osnovna_cena, Golemina golemina) : Pizza(ime,sostojki,osnovna_cena){
        this->golemina=golemina;
    }
    FlatPizza(char ime[20], char sostojki[100], double osnovna_cena) : Pizza(ime,sostojki,osnovna_cena){

    }
    double price(){
        if(golemina==mala){
            return osnovna_cena*1.10;
        } else if (golemina==golema){
            return osnovna_cena*1.30;
        } else {
            return osnovna_cena*1.50;
        }
    }
    friend ostream &operator<<(ostream &out, FlatPizza &p){
        out<<p.ime<<": "<<p.sostojki<<", ";
        if(p.golemina==mala) out <<"small - ";
        if(p.golemina==golema) out <<"big - ";
        if(p.golemina==familijarna) out <<"family - ";
        out<<p.price()<<endl;
        return out;
    }

};
class FoldedPizza : public Pizza{
private:
    bool brasno;
public:
    FoldedPizza(char ime[20], char sostojki[100], double osnovna_cena, bool brasno) : Pizza(ime,sostojki,osnovna_cena){
        this->brasno=brasno;
    }
    FoldedPizza(char ime[20], char sostojki[100], double osnovna_cena) : Pizza(ime,sostojki,osnovna_cena){
        brasno=true;
    }
    double price(){
        if(brasno==true){
            return osnovna_cena*1.10;
        } else {
            return osnovna_cena*1.30;
        }
    }
    friend ostream &operator<<(ostream &out, FoldedPizza &p){
        out<<p.ime<<": "<<p.sostojki<<", ";
        if(p.brasno) out<<"wf";
        else out<<"nwf";
        out<<" - "<<p.price()<<endl;
        return out;
    }
    void setBrasno(bool brasno_1){
        this->brasno=brasno_1;
    }

};

void expensivePizza(Pizza **niza, int n){
    Pizza *najskapa=niza[0];
    for(int i=0;i<n;i++){
        if(*najskapa < *niza[i]){
            najskapa=niza[i];
        }
    }
    FlatPizza *f = dynamic_cast<FlatPizza*>(najskapa);
    if(f != 0){
        cout<<*f;
    } else {
        FoldedPizza *fp = dynamic_cast<FoldedPizza*>(najskapa);
        if(fp != 0){
            cout<<*fp;
        }
    }
}


int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Golemina size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Golemina)s);
    cout << fp;

  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setBrasno(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Golemina)s);
    cout << *fp1;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Golemina)s);
    cout << *fp2;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setBrasno(false);
    cout << *fp4;

    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;

    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);

        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Golemina)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setBrasno(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
