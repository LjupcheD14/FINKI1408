#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


class Shape
{
protected:
    int a;
public:
    Shape()
    {
        a=0;
    }
    Shape(int a)
    {
        this->a=a;
    }

    virtual double plostina()=0;
    virtual void pecati()=0;
    virtual int getType()=0;
};

class Square : public Shape
{
public:
    Square(int a) : Shape(a) {}
    double plostina()
    {
        return a * a;
    }
    void pecati()
    {
        cout<<"Kvadrat so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 1;
    }
};

class Circle : public Shape
{
public:
    Circle(int a) : Shape(a) {}
    double plostina()
    {
        return 3.14 * a * a;
    }
    void pecati()
    {
        cout<<"Krug so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 2;
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a) : Shape(a) {}
    double plostina()
    {
        return (sqrt(3)/4) * a * a;
    }
    void pecati()
    {
        cout<<"Triagolnik so plostina = "<<plostina()<<endl;
    }
    int getType()
    {
        return 3;
    }
};

void checkNumTypes(Shape** niza, int n)
{
    int countTriangle=0,countCircle=0,countSquare=0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->getType()==1)
        {
            countSquare++;
        }
        if(niza[i]->getType()==2)
        {
            countCircle++;
        }
        if(niza[i]->getType()==3)
        {
            countTriangle++;
        }
    }
    cout<<"Broj na kvadrati vo nizata = "<<countSquare<<endl;
    cout<<"Broj na krugovi vo nizata = "<<countCircle<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<countTriangle<<endl;
}

int main()
{


    int n;
    cin >> n;

    Shape **niza=new Shape*[n];

    int classType;
    int side;

    for(int i = 0; i < n; ++i)
    {

        cin >> classType;
        cin >> side;

        if(classType==1)
        {
            niza[i]=new Square(side);
        }
        else if(classType==2)
        {
            niza[i]=new Circle(side);
        }
        else
        {
            niza[i]=new Triangle(side);
        }

    }


    for(int i = 0; i < n; ++i)
    {

        niza[i]->pecati();
    }

    checkNumTypes(niza, n);


    return 0;
}
