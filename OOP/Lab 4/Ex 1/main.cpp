#include <iostream>
#include <string.h>
using namespace std;
 
class List
{
private:
    int *numbers{nullptr};
    int numOfNums{0};
 
public:
    List()
    {
 
        numOfNums = 0;
        numbers = nullptr;
    }
 
    List(int *_numbers, int _numOfNums) : List()
    {
        numOfNums = _numOfNums;
 
        numbers = new int[numOfNums];
        for (int i = 0; i < numOfNums; i++)
        {
            numbers[i] = _numbers[i];
        }
    }
    List(const List &from)
    {
        if (this != &from)
        {
            numOfNums = from.numOfNums;
            delete[] numbers;
            numbers = new int[from.numOfNums];
            for (int i = 0; i < numOfNums; i++)
            {
                numbers[i] = from.numbers[i];
            }
        }
    }
 
    ~List()
    {
        delete[] numbers;
        numbers = nullptr;
    }
 
    int getNum()
    {
        return numOfNums;
    }
 
    int sum()
    {
        int total = 0;
        for (int i = 0; i < numOfNums; i++)
        {
            total += numbers[i];
        }
        return total;
    }
 
    double average()
    {
        return sum() / (double)numOfNums;
    }
 
    void pecati()
    {
 
       cout << " List info: " << numOfNums << ": ";
        for (int i = 0; i < numOfNums; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << "sum: " << sum() << " average: " << average() << endl;
    }
    List &operator=(const List &other)
    {
        if (this != &other)
        {
            delete[] numbers;
            numOfNums = other.numOfNums;
            numbers = new int[numOfNums];
            for (int i = 0; i < numOfNums; i++)
            {
                numbers[i] = other.numbers[i];
            }
        }
        return *this;
    }
};
class ListContainer
{
private:
    List *arr;
    int numOfLists;
    int attempts;
 
public:
    ListContainer()
    {
        numOfLists = 0;
        arr = nullptr;
        attempts = 0;
    }
    ListContainer(List *_arr, int _NumOfLists)
    {
        numOfLists = _NumOfLists;
        arr = new List[numOfLists];
        for (int i = 0; i < numOfLists; i++)
        {
            arr[i] = _arr[i];
        }
        attempts = 0;
    }
    ~ListContainer()
    {
        delete[] arr;
        arr = nullptr;
    }
 
    ListContainer(const ListContainer &other)
    {
        numOfLists = other.numOfLists;
        delete[] arr;
        arr = new List[numOfLists];
        for (int i = 0; i < numOfLists; i++)
        {
            arr[i] = other.arr[i];
        }
        attempts = other.attempts;
    }
 
    ListContainer &operator=(const ListContainer &from)
    {
        if (this != &from)
        {
 
            numOfLists = from.numOfLists;
            delete[] arr;
            arr = new List[numOfLists];
            for (int i = 0; i < numOfLists; i++)
            {
                arr[i] = from.arr[i];
            }
            attempts = from.attempts;
        }
        return *this;
    }
    void addNewList (List &L){
 
 
 
        List *tmp = new List [numOfLists+1];
        int flag = 0; 
 
        for (int i =0; i<numOfLists;i++){
            tmp[i] = this->arr[i];
        }
        for (int i=0;i<numOfLists;i++){
            if (L.sum() ==  tmp[i].sum()){
                flag = 1; 
            }
        }
        if (flag == 1) {attempts++;}
        if (flag==0){
        tmp[numOfLists++] = L; 
        delete [] this->arr;
        arr = new List [numOfLists];
        for (int i=0;i<numOfLists;i++){
            arr[i] = tmp[i];
        }
        }
 
 
    }
    void pecati (){
 
 
            if (numOfLists==0){
                cout <<"The list is empty" << endl; 
                return; 
            }
            for (int i=0;i<numOfLists;i++){
                cout << "List number: "<< i+1; 
                this->arr[i].pecati();
 
        }
 
            cout <<"Sum: " << sum() << " Average: " << average() << endl;
             cout <<"Successful attempts: " << numOfLists << " Failed attempts: " << attempts << endl; 
 
    }
    int sum (){
        int rez = 0; 
        for (int i=0;i<numOfLists;i++){
            rez += arr[i].sum(); 
        }
        return rez; 
    }
    double average (){
        double avg = 0.00; 
        int total =0; 
        for (int i=0;i<numOfLists;i++){
            total += arr[i].getNum();
            avg += arr[i].sum();
        }
        return avg/double(total); 
 
    }
 
};
 
 
int main()
{
 
    ListContainer lc;
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        int n;
        int niza[100];
 
        cin >> n;
 
        for (int j = 0; j < n; j++)
        {
            cin >> niza[j];
        }
 
        List l = List(niza, n);
 
        lc.addNewList(l);
    }
 
    int testCase;
    cin >> testCase;
 
    if (testCase == 1)
    {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.pecati();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.pecati();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();
    }
 
    else
    {
        lc.pecati();
    }
 
    return 0;
}
