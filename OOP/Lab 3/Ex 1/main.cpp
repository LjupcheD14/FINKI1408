#include<iostream>
#include<cstring>

using namespace std;

class Person {
private:
    char name[20];
    char lastname[20];
public:
    Person() {};

    Person(char *_name, char *_lastname) {
        strcpy(name, _name);
        strcpy(lastname, _lastname);
    }


    void print() {
        cout << name << " " << lastname << endl;
    }
};

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(){
        year = 1900;
        month = 1;
        day = 1;
    }
    Date(int year_, int month_, int day_){
        year = year_;
        month = month_;
        day = day_;
    }
    Date(const Date & d){
        year = d.year;
        month = d.month;
        day = d.day;
    }
    void print(){
        cout << year << "." << month << "." << day << endl;
    }
};

class Car {
private:
    Person person;
    Date date;
    float price;
public:
    Car() {}

    Car(Person _person, Date _date, float _price) {
        person = _person;
        date = _date;
        price = _price;
    }

    void print() {
        person.print();
        date.print();
        cout << "Price: " << price << endl;
    }

    int getPrice() {
        return price;
    };


};

void cheaperThan(Car *cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].getPrice() < price) {
            cars[i].print();
        }
    }
}

int main() {
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date, price);

        car.print();
    } else if (testCase == 2) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date, price);
        car.print();
    } else {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++) {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            cars[i] = Car(lik, date, price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }


    return 0;
}
