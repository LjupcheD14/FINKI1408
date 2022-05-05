#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Employee {
protected:
    char ime[50];
    int godini;
    int iskustvo;
public:
    Employee(char *ime="", int godini=0, int iskustvo=0){
        strcpy(this->ime,ime);
        this->godini=godini;
        this->iskustvo=iskustvo;
    }
    virtual double plata()=0;
    virtual double bonus()=0;

    bool operator==(Employee &e){
        return(godini == e.godini && bonus() == e.bonus());
    }
};
class SalaryEmployee : public Employee{
private:
    int osnovnaplata;
public:
    SalaryEmployee( char *ime="", int godini=0, int iskustvo=0, int osnovnaplata=0) : Employee(ime,godini,iskustvo){
        this->osnovnaplata=osnovnaplata;
    }
    double bonus(){
        return(iskustvo*osnovnaplata)/100;
    }
    double plata(){
        return osnovnaplata+bonus();
    }
};
class HourlyEmployee : public Employee{
private:
    int casovi;
    int plata_cas;
public:
    HourlyEmployee( char *ime="", int godini=0, int iskustvo=0, int casovi=0, int plata_cas=0) : Employee(ime,godini,iskustvo){
        this->casovi=casovi;
        this->plata_cas=plata_cas;
    }
    double plata(){
        return(casovi*plata_cas)+bonus();
    }
    double bonus(){
        if(casovi>320){
            return(casovi-320)*0.5*plata_cas;
        }
        return 0;
    }
};
class Freelancer : public Employee{
private:
    int broj_proekti;
    double proekti[15];
public:
    Freelancer(char *ime="", int godini=0, int iskustvo=0, int broj_proekti=0, double *proekti=0) : Employee(ime,godini,iskustvo){
        this->broj_proekti=broj_proekti;
        for(int i=0;i<broj_proekti;i++){
            this->proekti[i]=proekti[i];
        }
    }
    double bonus(){
        if(broj_proekti>5){
            return(broj_proekti-5)*1000;
        }
        return 0;
    }
    double plata(){
        double vkupno=0;
        for(int i=0;i<broj_proekti;i++){
            vkupno+=proekti[i];
        }
        return vkupno+bonus();
    }
};
class Company{
private:
    char ime[50];
    int broj_vraboteni;
    Employee **niza;
public:
    Company(const char *ime=""){
        strcpy(this->ime,ime);
        broj_vraboteni=0;
        niza=new Employee*[0];
    }
    ~Company(){
        delete[]niza;
    }
    Company&operator+=(Employee *e){
        Employee **tmp = new Employee*[broj_vraboteni+1];
        for(int i=0;i<broj_vraboteni;i++){
            tmp[i]=niza[i];
        }
        tmp[broj_vraboteni++]=e;
        delete[]niza;
        niza=tmp;
        return *this;
    }
    double vkupnaPlata(){
        double total=0;
        for(int i=0;i<broj_vraboteni;i++){
            total+=niza[i]->plata();
        }
        return total;
    }
    double filtriranaPlata(Employee *emp){
        double total=0;
        for(int i=0;i<broj_vraboteni;i++){
            if(*niza[i]==*emp){
                total+=niza[i]->plata();
            }
        }
        return total;
    }
    void pecatiRabotnici(){
        int countSalary=0, countHourly=0, countFree=0;
        cout<<"Vo kompanijata "<<ime<<" rabotat:"<<endl;
        for(int i=0;i<broj_vraboteni;i++){
            SalaryEmployee *se = dynamic_cast<SalaryEmployee *>(niza[i]);
            if(se != 0){
                countSalary++;
                continue;
            }
            HourlyEmployee *he = dynamic_cast<HourlyEmployee *>(niza[i]);
            if(he != 0){
                countHourly++;
                continue;
            }
            Freelancer *fl = dynamic_cast<Freelancer *>(niza[i]);
            if(fl != 0){
                countFree++;
                continue;
            }
        }
        cout<<"Salary employees: "<<countSalary<<endl;
        cout<<"Hourly employees: "<<countHourly<<endl;
        cout<<"Freelancers: "<<countFree<<endl;
    }
};


int main() {

char name[50];
cin >> name;
Company c(name);

int n;
cin >> n;

char employeeName[50];
int age;
int experience;
int type;

for (int i=0; i <n; ++i) {
  cin >> type;
  cin >> employeeName >> age >> experience;

  if (type == 1) {
    int basicSalary;
    cin >> basicSalary;
    c += new SalaryEmployee(employeeName, age, experience, basicSalary);
  }

  else if (type == 2) {
    int hoursWorked;
    int hourlyPay;
    cin >> hoursWorked >> hourlyPay;
    c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
  }

  else {
    int numProjects;
    cin >> numProjects;
    double projects[10];
    for (int i=0; i < numProjects; ++i) {
      cin >> projects[i];
    }
    c += new Freelancer(employeeName, age, experience, numProjects, projects);
  }
}

c.pecatiRabotnici();
cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

delete emp;
}
