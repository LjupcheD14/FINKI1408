#include <iostream>
using namespace std;

class Angle{
private:
    int deg,mint,sec;
public:
    Angle(){};
    ~Angle(){};

    int set_deg(int d){deg = d;}int set_mint(int m){mint = m;}int set_sec(int s){sec = s;}
    int getSeconds(){
        return sec;
    }
    int to_sec(){
        return sec + (mint*60) + (deg*3600);
    }
};

bool checker(int deg, int mint, int sec){
    return !(deg>360 || mint > 60 || mint <= 0 || deg <= 0 || sec < 0);
}

bool changeOfSeconds(Angle a, int sec){
    return a.getSeconds()!=sec;
}

int main(){

    Angle a1;
    int deg,mint,sec;
    cin>>deg>>mint>>sec;

    if(checker(deg, mint, sec)){
        a1.set_deg(deg);
        a1.set_mint(mint);
        a1.set_sec(sec);
        cout<<a1.to_sec();
        if(changeOfSeconds(a1,sec)){
            cout<<"Ne smeete da gi menuvate sekundite vo ramkite na klasata!"<<endl;
        }

    } else {
            cout<<"Nevalidni vrednosti za agol";
        }



    return 0;
}
