#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Number
{
public:
    virtual double doubleValue()=0;
    virtual int intValue()=0;
    virtual void print() =0;


    //TODO da se deklariraat trite cisto virtuelni metodi
};

bool operator ==(Number *n1,Number &n2)
{
    if(n1->doubleValue() == n2.doubleValue() && n1->intValue() == n2.intValue())
        return true;
    else
        return false;
}

//ТODO preoptovaruvanje na operatorot ==

class Integer : public Number   //TODO da se dodadi izraz za nasleduvanje od Number
{
private:
    //TODO da se deklariraat promenlivite
    int broj;

public:
    //TODO konstruktor so eden argument
    Integer(int broj)
    {
        this->broj=broj;
    }
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue()
    {
        return (double)broj;
    }
    int intValue()
    {
        return broj;
    }
    void print()
    {
        cout<<"Integer: "<<broj<<endl;
    }
};

class Double : public Number  //TODO da se dodadi izraz za nasleduvanje od Number
{
private:
    //TODO da se deklariraat promenlivite
    double broj;

public:
    //TODO konstruktor so eden argument
    Double(double broj)
    {
        this->broj=broj;
    }
    //TODO da se prepokrijat metodite od klasata Number
    double doubleValue()
    {
        return broj;
    }
    int intValue()
    {
        return (double) broj;
    }
    void print()
    {
        cout<<"Double: "<<broj<<endl;
    }
};

class Numbers
{
private:
    //TODO deklariranje na promenlivite
    Number **niza;
    int dolzina;

public:
    //TODO default konstruktor
    Numbers()
    {
        dolzina=0;
        niza = new Number*[0];
    }

    //TODO copy konstruktor
    Numbers(const Numbers &n)
    {
        this->niza = new Number*[dolzina];
        for(int i=0; i<dolzina; i++)
        {
            this->niza[i]=n.niza[i];
        }
        this->dolzina=n.dolzina;
    }

    //TODO operator =
    Numbers &operator=(const Numbers &n)
    {
        if(this != &n)
        {
            delete[]niza;
            this->niza = new Number*[dolzina];
            for(int i=0; i<dolzina; i++)
            {
                this->niza[i]=n.niza[i];
            }
            this->dolzina=n.dolzina;
        }
        return *this;
    }

    //TODO destruktor
    ~Numbers()
    {
        delete[] niza;
    }

    //TODO operator += (operatorot da prima pointer od objekt od Number, a ne referenca)
    Numbers &operator+=(Number *num)
    {
        for(int i=0; i<dolzina; i++)
        {
            if(niza[i]==*num)
            {
                return *this;
            }
        }
        Number **tmp = new Number*[dolzina+1];
        for(int i=0; i<dolzina; i++)
        {
            tmp[i]=niza[i];
        }
        tmp[dolzina++]=num;
        delete[] niza;
        niza=tmp;
        return *this;
    }
    //TODO void statistics()
    void statistics()
    {
        double sum=0;
        for(int i=0; i<dolzina; i++)
        {
            sum+=niza[i]->doubleValue();
        }
        int countInteger=0, countDouble=0, sumInt=0;
        double sumDouble=0;
        for(int i=0; i<dolzina; i++)
        {
            Integer *in = dynamic_cast<Integer *>(niza[i]);
            if(in != 0)
            {
                countInteger++;
                sumInt+=niza[i]->intValue();
            }
            Double *d=dynamic_cast<Double *>(niza[i]);
            if( d!=0)
            {
                countDouble++;
                sumDouble+=niza[i]->doubleValue();
            }
        }
        cout<<"Count of numbers: "<<this->dolzina<<endl;
        cout<<"Sum of all numbers: "<<sum<<endl;
        cout<<"Count of integer numbers: "<<countInteger<<endl;
        cout<<"Sum of integer numbers: "<<sumInt<<endl;
        cout<<"Count of double numbers: "<<countDouble<<endl;
        cout<<"Sum of double numbers: "<<sumDouble<<endl;
    }

    //TODO void integersLessThan (Integer n)
    void integersLessThan(Integer n)
    {
        int cnt=0;
        int max=n.intValue();
        for(int i=0; i<dolzina; i++)
        {
            Integer *in = dynamic_cast<Integer *>(niza[i]);
            if(in)
            {
                if(niza[i]->intValue()<max)
                {
                    niza[i]->print();
                    cnt++;
                }
            }
        }
        if(cnt==0)
            cout<<"None"<<endl;
    }

    //TODO void doublesBiggerThan (Double n)

    void doublesBiggerThan(Double n)
    {
        int cnt=0;
        int min=n.doubleValue();
        for(int i=0; i<dolzina; i++)
        {
            Double *d=dynamic_cast<Double *>(niza[i]);
            if(d)
            {
                if(niza[i]->doubleValue()>min)
                {
                    niza[i]->print();
                    cnt++;
                }
            }
        }
        if(cnt==0)
        {
            cout<<"None"<<endl;
        }
    }
};

int main()
{

    int n;
    cin>>n;
    Numbers numbers;
    for (int i=0; i<n; i++)
    {
        int type;
        double number;
        cin>>type>>number;
        if (type==0) //Integer object
        {
            Integer * integer = new Integer((int) number);
            numbers+=integer;
        }
        else
        {
            Double * doublee = new Double(number);
            numbers+=doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin>>lessThan;
    cin>>biggerThan;

    cout<<"STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
    numbers.integersLessThan(Integer(lessThan));
    cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}
