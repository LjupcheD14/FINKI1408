#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Exception
{

public:
    void message()
    {
        cout<<"Ne moze da se vnese dadeniot trud"<<endl;
    }
};
class Trud
{
private:
    char znak;
    int godina;
public:
    Trud(const char znak='C',int godina=0)
    {
        this->znak=toupper(znak);
        this->godina=godina;
    }
    char getZnak()
    {
        return znak;
    }
    int getGodina()
    {
        return godina;
    }
    friend istream&operator>>(istream &i,Trud &t)
    {
        i>>t.znak>>t.godina;
        return i;
    }
};
class Student
{
private:
    char ime[30];
    int indeks;
    int upis;
    int niza[50];
    int n;
public:
    Student(const char *ime="",int indeks=0,int upis=0,int *niza=0,int n=0)
    {
        strcpy(this->ime,ime);
        this->indeks=indeks;
        this->upis=upis;
        for(int i=0;i<n;i++)
        {
            this->niza[i]=niza[i];
        }
        this->n=n;
    }
    int getIndeks()
    {
        return indeks;
    }
    int getUpis()
    {
        return upis;
    }
    virtual double rang()
    {
        double total=0;
        for(int i=0;i<n;i++)
        {
            total+=niza[i];
        }
        return total/(n*1.0);
    }
    friend ostream&operator<<(ostream &out, Student &st)
    {
            out<<st.indeks<<" "<<st.ime<<" ";
            out<<st.upis<<" ";
            out<<st.rang()<<endl;
            return out;
    }
};
class PhDStudent : public Student
{
private:
    Trud *trudovi;
    int broj;
    static int K;
    static int T;
public:
    PhDStudent(const char *ime="",int indeks=0,int upis=0,int *niza=0,int n=0, Trud *t=0, int nt=0) : Student(ime,indeks,upis,niza,n)
    {
        trudovi=new Trud[100];
        int brojac=0;
        for(int i=0;i<nt;i++)
        {
            try{
                if(this->getUpis() > t[i].getGodina())
                    throw Exception();
                trudovi[brojac++]=t[i];
            }
            catch(Exception &e)
            {
                e.message();
            }
        }
        this->broj=brojac;
    }
    double rang()
    {
        double total=0;
        for(int i=0;i<broj;i++)
        {
            if(trudovi[i].getZnak() == 'C')
            {
                total+=K;
            }
            else
            {
                total+=T;
            }
        }
        return Student::rang()+total;
    }
    static void setConf(int number)
    {
        K=number;
    }
    static void setJournal(int number)
    {
        T=number;
    }
    PhDStudent&operator+=(Trud &t)
    {
        if(t.getGodina() < getUpis())
        {
            throw Exception();
        }
        trudovi[broj++]=t;
        return *this;
    }
    ~PhDStudent()
    {
        delete[]trudovi;
    }
};
int PhDStudent::K = 1;
int PhDStudent::T = 3;
int main()
{
	int testCase;
	cin >> testCase;

	int god, indeks, n, god_tr, m, n_tr;
	int izbor; //0 za Student, 1 za PhDStudent
	char ime[30];
	int oceni[50];
	char tip;
	Trud trud[50];

	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		Student s(ime, indeks, god, oceni, n);
		cout << s;

		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        for(int i=0;i<m;i++)
        {
            if(niza[i]->getIndeks() == indeks)
            {
                PhDStudent *temp = dynamic_cast<PhDStudent*>(niza[i]);
                if(temp != 0)
                {
                    try
                    {
                        *temp+=t;
                    }
                    catch (Exception &e)
                    {
                        e.message();
                    }
                }
                else
                {
                    cout<<"Ne postoi PhD student so indeks "<<indeks<<endl;
                    break;
                }
            }
        }
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 3){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2


		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 4){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 5){
		cout << "===== Testiranje na isklucoci ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;

		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot

		    for(int i=0;i<m;i++)
            {
                if(niza[i]->getIndeks() == indeks){
                    try
                    {
                        PhDStudent *temp=dynamic_cast<PhDStudent*>(niza[i]);
                        *temp+=t;
                    }
                    catch(Exception &e)
                    {
                        e.message();
                    }
                }
            }

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 6){
		cout << "===== Testiranje na static clenovi ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		int conf, journal;
		cin >> conf;
		cin >> journal;

        //postavete gi soodvetnite vrednosti za statickite promenlivi
        for(int i=0;i<m;i++)
        {
            PhDStudent *temp = dynamic_cast<PhDStudent*>(niza[i]);
            if(temp != 0)
            {
                temp->setConf(conf);
                temp->setJournal(journal);
            }
        }

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}

	return 0;
}
