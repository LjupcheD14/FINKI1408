#include <iostream>

using namespace std;

class A{
private:
    int x;
public:
    A(){
        x=1;
        cout<<"A - constructor"<<endl;
    }
    A(A&a){
        cout<<"A - copy"<<endl;
        x=a.x;
    }
    ~A(){
        cout<<"A - destructor"<<endl;
    }
};

class B{
private:
    int x;
public:
    B(){
        x=1;
        cout<<"B - constructor"<<endl;
    }
    B(B&a){
        cout<<"B - copy"<<endl;
        x=a.x;
    }
    ~B(){
        cout<<"B - destructor"<<endl;
    }
};

class C{
private:
    A a;
    B b;
public:
    C(A a, B b){
        cout<<"C - constructor"<<endl;
        this->a=a;
        this->b=b;
    }
    ~C(){
        cout<<"C - destructor"<<endl;
    }
};

int main()
{

    A a;
    B b;
    C c(a,b);
    return 0;
}

///

#include <iostream>

using namespace std;

class A{
public:
    A(){
        cout<<'a';
    }
    ~A(){
        cout<<'A';
    }
};

class B{
public:
    B(){
        cout<<'b';
    }
    ~B(){
        cout<<'B';
    }
    A a;
};

int main()
{
    B b;
    return 0;
}

///

#include <iostream>

using namespace std;

class A{
public:
    A(){
        cout<<'a';
    }
    ~A(){
        cout<<'A';
    }
};

class B{
public:
    B(){
        cout<<'b';
    }
    ~B(){
        cout<<'B';
    }
};

class C{
public:
    C(){
        cout<<'c';
    }
    ~C(){
        cout<<'C';
    }
};

B b;

void foo(){
    C c;
}

int main()
{
    foo();
    A a;
    return 0;
}

///

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class sp{
    int x,y,z;
public:
    sp(int xx, int yy=2, int zz=3) : y(yy), z(zz){
        x=1;
    }
    sp &div(const sp& v){
        x/=v.x;
        y/=v.y;
        z/=v.z;
        return *this;
    }
    void show(){
        cout<<x<<','<<y<<','<<z<<endl;
    }
};

int main()
{
    sp a(1,2,3), b(1,2), c();
    a.div(b).div(c);
    a.show();

    return 0;
}


///

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int x=5;

int main()
{
    int x=10;
    {
        int x=15;
        cout<<::x<<" ";
    }
    cout<<::x<<" ";

    return 0;
}


///

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Test{
public:
    int x;
    Test(){
        cout<<"1 ";
    }
    Test(const Test &t){
        x=t.x;
        cout<<"2 ";
    }
    Test &operator=(const Test &t){
        x=t.x;
        cout<<"3 ";
        return *this;
    }
    Test operator+(const Test &t){
        Test r(t);
        r.x += t.x;
        cout<<"4 ";
        return r;
    }
};

int main()
{
    Test t1;
    Test t2 = t1;
    t1 = t1 + t2;
    return 0;
}


///

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class A{
    int x;
public:
    void set(int xx){
        x=xx;
    }
    int get(){
        return x;
    }
};

class B : public A{
public:
    B(){
        set(4);
    }
};

class C{
public:
    void print(int i){
        cout<<i<<endl;
    }
};

class D : public B, public C{
public:
    int f(){
        return get()*get();
    }
};

int main()
{
    D d;
    d.print(d.f());

    return 0;
}


///

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class P{
public:
    void print(){
        cout<<"Inside P";
    }
};

class Q : public P{
public:
    void print(){
        cout<<"Inside Q";
    }
};

class R : public Q{

};

int main()
{
    R r;
    r.print();

    return 0;
}

///


