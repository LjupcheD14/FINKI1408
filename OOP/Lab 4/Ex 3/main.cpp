#include<iostream>
#include<cstring>

using namespace std;

class Avtomobil {
private:
    char color[30];
    char brand[30];
    char model[30];
    void copy(const Avtomobil &from){
        strcpy(color, from.color);
        strcpy(brand, from.brand);
        strcpy(model, from.model);
    }
public:
    Avtomobil() {}
    ~Avtomobil() {}
    Avtomobil(char *_color, char *_brand, char *_model) {
        strcpy(color, _color);
        strcpy(brand, _brand);
        strcpy(model, _model);
    }
    Avtomobil &operator=(const Avtomobil &from) {
        if (this != &from) {
            copy(from);
        }
        return *this;
    }
    Avtomobil(const Avtomobil &from) {
        copy(from);
    }
    void pecati() {
        cout << color << " " << brand << " " << model << endl;
    }
};

class ParkingPlac {
private:
    char address[20];
    char *placId;
    int parkingPrice;
    int profit;
    Avtomobil *arr = nullptr;
    int num;
    void freeMemory(){
        delete[] placId;
        delete[] arr;
    }
public:
    ParkingPlac() {
        placId = new char[0];
    }
    ParkingPlac(char *_address, char *_placId, int _parkingPrice) {
        strcpy(address, _address);
        this->placId = new char[strlen(_placId) + 1];
        strcpy(placId, _placId);
        parkingPrice = _parkingPrice;
    }
    ~ParkingPlac() {
        freeMemory();
    }
    ParkingPlac(const ParkingPlac &p) {
        delete[] arr;
        strcpy(address, p.address);
        placId = new char[strlen(p.placId) + 1];
        strcpy(placId, p.placId);
        parkingPrice = p.parkingPrice;
        profit = p.profit;
        num = p.num;
        arr = new Avtomobil[num];
        for (int i = 0; i < num; i++) {
            this->arr[i] = p.arr[i];
        }
    }
    ParkingPlac &operator=(const ParkingPlac &p) {
        if (this != &p) {
            freeMemory();
            strcpy(address, p.address);
            placId = new char[strlen(p.placId) + 1];
            strcpy(placId, p.placId);
            parkingPrice = p.parkingPrice;
            profit = p.profit;
            num = p.num;
            arr = new Avtomobil[num];
            for (int i = 0; i < num; i++) {
                arr[i] = p.arr[i];
            }
        }
        return *this;
    }
    char *getId() {
        return this->placId;
    }
    void pecati() {
        if (profit != 0) {
            cout << placId << " " << address << " - " << profit << " denari" << endl;
        } else {
            cout << placId << " " << address << endl;
        }
    }
    void platiCasovi(int casovi) {
        profit += casovi * parkingPrice;
    }
    bool daliIstaAdresa(ParkingPlac P) {
        if (!strcmp(address, P.address)) {
            return true;
        } else
            return false;
    }
    void parkirajVozilo(Avtomobil novoVozilo) {
        Avtomobil *tmp = new Avtomobil[num + 1];
        for (int i = 0; i < num; i++) {
            tmp[i] = arr[i];
        }
        tmp[num++] = novoVozilo;
        delete[] arr;
        arr = tmp;
        tmp = nullptr;
    }
    void pecatiParkiraniVozila() {
        cout << "Vo parkingot se parkirani slednite vozila: " << endl;
        for (int i = 0; i < num; i++) {
            cout << i + 1 << ".";
            arr[i].pecati();
        }
    }
};


int main() {

    ParkingPlac p[100];
    int n, m;
    char adresa[50], id[50];
    int brojcasovi, cenacas;
    cin >> n;
    if (n > 0) {


        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(adresa, 50);
            cin >> id >> cenacas;

            ParkingPlac edna(adresa, id, cenacas);

            //povik na operatorot =
            p[i] = edna;
        }

        //plakjanje
        cin >> m;
        for (int i = 0; i < m; i++) {

            cin >> id >> brojcasovi;

            int findId = false;
            for (int j = 0; j < m; j++) {
                if (strcmp(p[j].getId(), id) == 0) {
                    p[j].platiCasovi(brojcasovi);
                    findId = true;
                }
            }
            if (!findId)
                cout << "Ne e platen parking. Greshen ID." << endl;
        }

        cout << "=========" << endl;
        ParkingPlac pCentar("Cvetan Dimov", "C10", 80);
        for (int i = 0; i < n; i++)
            if (p[i].daliIstaAdresa(pCentar))
                p[i].pecati();
    } else {

        ParkingPlac najdobarPlac("Mars", "1337", 1);
        int brVozila;
        cin >> brVozila;
        for (int i = 0; i < brVozila; ++i) {

            char boja[20];
            char brend[20];
            char model[20];

            cin >> boja >> brend >> model;
            Avtomobil novAvtomobil(boja, brend, model);
            najdobarPlac.parkirajVozilo(novAvtomobil);
        }
        if (brVozila != 0)
            najdobarPlac.pecatiParkiraniVozila();

    }
    return 0;
}
