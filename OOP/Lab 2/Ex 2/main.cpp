#include <iostream>
using namespace std;

class Krug {
private:
    float radius;
    const float pi = 3.14;
public:
    Krug(){};
    Krug(float r){
        radius = r;
    }
    ~Krug(){};
    float P(){
        return 2*radius*pi;
    }
    float L(){
        return pi*(radius*radius);
    }
    bool is_equal(){
        Krug k(radius);
        return k.P() == k.L();
    }
};

int main() {
	float r;
	cin >> r;
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
	Krug k(r);
	cout << k.P() << endl;
	cout << k.L() << endl;
	cout << k.is_equal() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
	return 0;
}
