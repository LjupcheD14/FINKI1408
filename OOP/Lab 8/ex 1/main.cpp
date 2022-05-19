#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape.\n";
    }
};

class Rectangle : public Shape{
    public:
    void draw(){
        cout<<"Drawing a rectangle.\n";
    }
};


int main() {
    Shape* shape;

    
    Shape s;
    shape = &s;
    
    shape->draw();

    
    Rectangle rec;
    shape=&rec;
    shape->draw();
    

    return 0;
}
