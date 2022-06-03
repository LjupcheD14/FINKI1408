

/// Overloading operator
///Operator <<
friend ostream &operator<<(ostream &out, Vozac &v)
    {
        out<<v.ime<<endl<<v.vozrast<<endl<<v.broj_trki<<endl;
        if(v.veteran) out<<"VETERAN"<<endl;
        return out;
    }
///Operator ==
bool operator==(Vozac &v)
    {
        return this->zarabotuvacka()==v.zarabotuvacka();
    }
///Operator <
bool operator<(Pizza &p){
        return this->price() < p.price();
    }
///Operator +
Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
///Operator +=MobileServis&operator+=(Device &d){
        if(d.getGodina()>2019 || d.getGodina()<2000){
            throw InvalidProductionDate();
        }
        Device *tmp = new Device[broj+1];
        for(int i=0;i<broj;i++){
            tmp[i]=niza[i];
        }
        tmp[broj++]=d;
        delete[]niza;
        niza=tmp;
        return *this;
    }
FINKI_bookstore &operator+=(Customer &c)
    {
        for(int i=0; i<num; i++)
        {
            if(!strcmp(c.getEmail(),customers[i].getEmail()))
              throw UserExistsException();
        }
        Customer *cts = new Customer[++num];
        for(int i=0; i<num-1; i++)
        {
            cts[i]=customers[i];
        }
        cts[num-1]=c;
        delete[] customers;
        customers=cts;
        return *this;
    }
///Да се напше надворешна функција soIstaZarabotuvachka која како аргументи прима низа од покажувачи од класата Vocac, нивниот број, како и покажувач кон ојбект од возач и враќа како резултат бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.
int soIstaZarabotuvachka(Vozac **niza, int n, Vozac *v)
{
    int broj=0;
    for(int i=0; i<n; i++)
    {
        if(niza[i]->zarabotuvacka()==v->zarabotuvacka())
        {
            broj++;
        }
    }
    return broj;
}
///Student& vratiNajdobroRangiran(Student ** studenti, int n ) што враќа референца кон студентот кој има најмногу бодови од листата на дадените n студенти (studenti). Да забележиме дека оние демонстратори кои не држат лабораториски вежби ќе земеме дека имаат 0 бодови. Да забележиме и дека во примерите секогаш има точно еден студент кој има најголем број на бодови.
Student &vratiNajdobroRangiran(Student **studenti, int n){
    Student *najdobar=studenti[0];
    for(int i=0;i<n;i++){
        try{
        if(studenti[i]->getBodovi() > najdobar->getBodovi()){
                najdobar=studenti[i];
           }
        }
    catch(NoCourseException &n){
        n.message();
        }
    }
    return *najdobar;
}
///void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n) - која од дадена листа на студенти, ќе ги испечати само оние кои држат лабораториски вежби на курсот kurs.
void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n){
    for(int i=0;i<n;i++){
        Demonstrator *tmp = dynamic_cast<Demonstrator*>(studenti[i]);
        if(tmp != 0){
            for(int j=0;j<tmp->getBrojKursevi();j++){
                if((*tmp)[j]==kurs){
                    tmp->pecati();
                    cout<<endl;
                    break;
                }
            }
        }
    }
}
///функција dodadiDopolnitelenPin(char * smetka, int novPin) во која на картичката со дадена трансакциона сметка се додава нов дополнителен пин код. Ако тоа не е можно функцијата не прави ништо
void dodadiDopolnitelenPin(char *smetka, int novPin){
        for(int i=0;i<broj;i++){
            bool flag=false;
            int index;
            if(strcmp(karticki[i]->getSmetka(),smetka)==0){
                flag=true;
                index=i;
            }
            if(flag){
                SpecijalnaKarticka *sk=dynamic_cast<SpecijalnaKarticka*>(karticki[index]);
                if(sk!=0){
                    try{
                        *sk+=novPin;
                    }
                    catch (OutOfBoundsException e){
                        throw e;
                    }
                }
            }
        }
    }
///void najskapKoncert(Koncert ** koncerti, int n) – во која ќе се испечати називот и цената на најскапиот концерт во низата. Дополнително, да се испечати и колку од концертите се електронски, а колку не во формат:
void najskapKoncert(Koncert **koncerti, int n)
{
    int counter=0;
    Koncert *najskap = koncerti[0];
    for(int i=0; i<n; i++)
    {
        ElektronskiKoncert *tmp = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
        if(tmp!=0)
        {
            counter++;
        }
        if(i!=0)
        {
            if(koncerti[i]->cena() > najskap->cena())
            {
                najskap=koncerti[i];
            }
        }
    }
    cout<<"Najskap koncert: "<<najskap->getNaziv()<<" "<<najskap->cena()<<endl;
    cout<<"Elektronski koncerti: "<<counter<<" od vkupno "<<n<<endl;
}
///bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski) – во која ќе се прабарува концерт кој имаат ист назив како променливата naziv. Доколку променливата elektronski е true, треба да се пребарува само низ електронските концерти, во спротивно се пребаруваат сите концерти. Доколку е пронајден концертот, се печати неговиот назив и цена и функцијата враќа true. Доколку не е пронајден концертот, функцијата враќа false. Можно е да има повеќе концерти со ист назив. (10 поени)
bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski)
{
    if(elektronski==true)
    {
        for(int i=0; i<n; i++)
        {
            ElektronskiKoncert *tmp = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
            if(tmp!=0)
            {
                if(strcmp(koncerti[i]->getNaziv(),naziv)==0)
                {
                    cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                    return true;
                }
            }

        }

    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(strcmp(koncerti[i]->getNaziv(),naziv)==0)
            {
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
        }
    }
    return false;
}
///Set static void
static void setJournal(int number)
    {
        T=number;
    }
int PhDStudent::T = 3;
///Функција void najniskaCena() со која се печати огласот што има најниска цена. Ако има повеќе огласи со иста најниска цена, да се испечатат податоците за првиот од нив.
void najniskaCena()
    {
        Oglas temp = niza[0];
        for(int i=1;i<broj;i++)
        {
            if(niza[i].getCena() < temp.getCena())
            {
                temp=niza[i];
            }
        }
        cout<<temp;
    }
///Функција void oglasOdKategorija(const char *k) со која се печатат сите огласи од категоријата k што е проследена како влезен аргумент на методот.
void oglasiOdKategorija(const char *k)
    {
        for(int i=0;i<broj;i++)
        {
            if(strcmp(niza[i].getKategorija(),k) == 0)
            {
                cout<<niza[i]<<endl;
            }
        }
    }
///Да се дефинира надворешна функција brojPretstaviNaDelo која како аргумент прима низа од покажувачи кон претстави кои се прикажале во еден месец, големина на низата и едно дело. Оваа функција пресметува на колку од дадените претстави е прикажано даденото дело.
int brojPretstaviNaDelo (Pretstava **niza, int n, Delo d){
    int vkupno=0;
    for(int i=0;i<n;i++){
        if(niza[i]->getDelo()==d){
            vkupno++;
        }
    }
    return vkupno;
}
///Да се имплементира функција vkupno_SMS со потпис:
///void vkupno_SMS(SMS** poraka, int n)
///во која се печати вкупниот број на регуларни СМС пораки и нивната вкупна цена, како и бројот на специјални СМС пораки и нивната вкупна цена во проследената низа посебно.
void vkupno_SMS(SMS **poraka, int n){
    double vkupnoREG=0,vkupnoSPEC=0;
    int brojacREG=0,brojacSPEC=0;
    for(int i=0;i<n;i++){
        SpecialSMS *tmp = dynamic_cast<SpecialSMS*>(poraka[i]);
        if(tmp!=0){
            brojacSPEC++;
            vkupnoSPEC+=tmp->SMS_cena();
        } else {
            brojacREG++;
            vkupnoREG+=poraka[i]->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<brojacREG<<" regularni SMS poraki i nivnata cena e: "<<vkupnoREG<<endl;
    cout<<"Vkupno ima "<<brojacSPEC<<" specijalni SMS poraki i nivnata cena e: "<<vkupnoSPEC<<endl;
}
///функција postaviOpisnaOcenka(char * ime, char* opisnaOcenka) во која на студентот на курсот со даденото име му се поствува описна оценка. Ако тоа не е можно функцијата не прави ништо
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
///Да се имплементира функција pecatiPoloshiPonudi што на влез прима низа од понуди за транспорт на патник, бројот на елементите од низата и една понуда T. Функцијата ја печати дестинацијата, растојанието до дестинацијата и цената за понудите од низата кои се поскапи од понудата T сортирани во растечки редослед по растојанието до дестинацијата (погледни го повикот на функцијата)
void pecatiPoloshiPonudi (Transport **ponudi, int n, Transport &t){
    Transport *tmp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ponudi[i]->cena() > ponudi[j]->cena()){
                tmp=ponudi[i];
                ponudi[i]=ponudi[j];
                ponudi[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ponudi[i]->cena() > t.cena()){
            cout<<*ponudi[i];
        }
    }
}
