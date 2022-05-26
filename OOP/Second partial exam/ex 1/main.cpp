#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class FINKI_Education
{
protected:
    char ISBN[20];
    char naslov[50];
    char avtor[30];
    double osnovna_cena;
public:
    FINKI_Education(char ISBN[20], char naslov[50], char avtor[30], double osnovna_cena)
    {
        strcpy(this->ISBN,ISBN);
        strcpy(this->naslov,naslov);
        strcpy(this->avtor,avtor);
        this->osnovna_cena=osnovna_cena;
    }
    virtual double bookPrice()=0;

    bool operator>(FINKI_Education &finki)
    {
        return bookPrice()>finki.bookPrice();
    }

    friend ostream &operator<<(ostream &out, FINKI_Education &finki)
    {
        out<<finki.ISBN<<": "<<finki.naslov<<", "<<finki.avtor<<" "<<finki.bookPrice()<<endl;
        return out;
    }

    void setISBN(char ISBN[20])
    {
        strcpy(this->ISBN, ISBN);
    }

};

class Online_kniga : public FINKI_Education
{
private:
    char *url;
    int golemina;
public:
    Online_kniga(char ISBN[20], char naslov[50], char avtor[30], double osnovna_cena, char *url,int golemina) : FINKI_Education(ISBN,naslov,avtor,osnovna_cena)
    {
        this->golemina=golemina;
        this->url = new char[strlen(url)];
        strcpy(this->url,url);
    }
    double bookPrice()
    {
        if(golemina>20)
            return osnovna_cena*1.2;
        else
            return osnovna_cena;
    }
};
class Pecatena_kniga : public FINKI_Education
{
private:
    bool zaliha;
    double masa;
public:
    Pecatena_kniga(char ISBN[20], char naslov[50], char avtor[30], double osnovna_cena, bool zaliha=false, double masa=0) : FINKI_Education(ISBN,naslov,avtor,osnovna_cena)
    {
        this->zaliha=zaliha;
        this->masa=masa;
    }
    double bookPrice()
    {
        if(masa>0.7)
        {
            return osnovna_cena * 1.15;
        }
        else
        {
            return osnovna_cena;
        }
    }
};

void mostExpensiveBook(FINKI_Education **knigi, int dolzina)
{
    FINKI_Education *najskapa = knigi[0];
    int broj_pecateni=0, broj_online=0;
    for(int i=0; i<dolzina; i++)
    {
        Online_kniga *o=dynamic_cast<Online_kniga*>(knigi[i]);
        if(o!=0)
        {
            broj_online++;
            if(o->bookPrice()>najskapa->bookPrice()) najskapa=o;
        }
        else
        {
            Pecatena_kniga *p=dynamic_cast<Pecatena_kniga*>(knigi[i]);
            if(p!=0)
            {
                broj_pecateni++;
                if(p->bookPrice()>najskapa->bookPrice()) najskapa=p;
            }
        }
    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<broj_online<<endl;
    cout<<"Total number of print books: "<<broj_pecateni<<endl;
    cout<<"The most expensive book is: "<<endl;
    cout<<*mostExpensiveBook<<endl;
}


int main()
{

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    FINKI_Education  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i < n; i++)
        {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new Online_kniga(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2)
    {
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        Online_kniga ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        Online_kniga ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3)
    {
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i < n; i++)
        {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new Pecatena_kniga(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4)
    {
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new FINKI_Education *[n];

        for (int i = 0; i<n; i++)
        {

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1)
            {

                cin >> url;
                cin >> size;

                books[i] = new Online_kniga(isbn, title, author, price, url, size);

            }
            else
            {
                cin >> weight;
                cin >> inStock;

                books[i] = new Pecatena_kniga(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}
