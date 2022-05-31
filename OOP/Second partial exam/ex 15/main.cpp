#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;


using namespace std;
class BadInputException
{
public:
    void message()
    {
        cout<<"Greshna opisna ocenka"<<endl;
    }
};
class StudentKurs{
   protected:
       char ime[30];
       int ocenka;
       bool daliUsno;
       static int MAX;
        static const int MINOCENKA = 6;
   public:
    StudentKurs(const char* ime,int finalenIspit){
       strcpy(this->ime,ime);
       this->ocenka=finalenIspit;
       this->daliUsno=false;
     }
     bool getDaliUsno()
     {
         return daliUsno;
     }
     char *getIme()
     {
         return ime;
     }
     void setOcenka(int number)
     {
         ocenka=number;
     }
     static void setMAX(int number)
     {
         MAX=number;
     }
     static int getMAX()
     {
         return MAX;
     }
     friend ostream&operator<<(ostream &out,const StudentKurs &sk)
     {
         return out << sk.ime << " --- " << sk.ocenka << endl;
     }
     int getOcenka()
     {
         return ocenka;
     }
     static int getMIN()
     {
         return MINOCENKA;
     }
     virtual ~StudentKurs()
     {

     }
};
int StudentKurs::MAX = 10;

class StudentKursUsno : public StudentKurs
{
private:
    char *ocenka2;
public:
    StudentKursUsno(const char *ime,int finalenIspit) : StudentKurs(ime,finalenIspit)
    {
        daliUsno = true;
    }
    ~StudentKursUsno()
    {
        delete[]ocenka2;
    }
    StudentKursUsno&operator+=(const char *text)
    {
        char temp[20];
        int brojac=0;
        int flag=0;
        for(int i=0;i<strlen(text);i++)
        {
            if(!isalpha(text[i]))
            {
                flag=1;
            }
            else
            {
                temp[brojac++]=text[i];
            }
        }
        temp[brojac]='\0';
        this->ocenka2 = new char[strlen(temp)+1];
        strcpy(this->ocenka2,temp);
        if(strcmp(ocenka2,"odlicen") == 0)
        {
            if(ocenka+2 <= MAX)
            {
                ocenka+=2;
            }
        }
        else if(strcmp(ocenka2,"dobro") == 0)
        {
            if(ocenka+1 <= MAX){
                ocenka+=1;
            }
        }
        else if(strcmp(ocenka2,"losho") == 0)
        {
            ocenka-=1;
        }
        if(flag == 1)
        {
            throw BadInputException();
        }
        return *this;
    }

};

class KursFakultet{
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;
public:
    KursFakultet(const char *naziv, StudentKurs** studenti,int broj ){
      strcpy(this->naziv,naziv);
      for (int i=0;i<broj;i++){
        if (studenti[i]->getDaliUsno()){
            this->studenti[i]=new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
        }
        else this->studenti[i]=new StudentKurs(*studenti[i]);
      }
      this->broj=broj;
    }
    ~KursFakultet(){
    for (int i=0;i<broj;i++) delete studenti[i];
    }
    void pecatiStudenti()
    {
        cout<<"Kursot "<<naziv<<" go polozile:"<<endl;
        for(int i=0;i<broj;i++)
        {
            if(studenti[i]->getOcenka()>=studenti[i]->getMIN())
            {
                if(studenti[i]->getOcenka() > studenti[i]->getMAX())
                {
                    studenti[i]->setOcenka(studenti[i]->getMAX());
                }
                cout<<*studenti[i];
            }
        }
    }
    void postaviOpisnaOcenka(const char *ime,const char *opisnaOcenka)
    {
        for(int i=0;i<broj;i++)
        {
            if(strcmp(studenti[i]->getIme(),ime) == 0 && studenti[i]->getDaliUsno() == true)
            {
                StudentKursUsno *temp=dynamic_cast<StudentKursUsno*>(studenti[i]);
                if(temp != 0)
                {
                    *temp+=opisnaOcenka;
                    break;
                }
            }
        }
    }
};

int main(){

StudentKurs **niza;
int n,m,ocenka;
char ime[30],opisna[10];
bool daliUsno;
cin>>n;
niza=new StudentKurs*[n];
for (int i=0;i<n;i++){
   cin>>ime;
   cin>>ocenka;
   cin>>daliUsno;
   if (!daliUsno)
    niza[i]=new StudentKurs(ime,ocenka);
   else
    niza[i]=new StudentKursUsno(ime,ocenka);
}

KursFakultet programiranje("OOP",niza,n);
for (int i=0;i<n;i++) delete niza[i];
delete [] niza;
cin>>m;

for (int i=0;i<m;i++){
   cin>>ime>>opisna;
   try{
   programiranje.postaviOpisnaOcenka(ime,opisna);
   }
   catch(BadInputException &b)
   {
       b.message();
   }
}

StudentKurs::setMAX(9);

programiranje.pecatiStudenti();

}
