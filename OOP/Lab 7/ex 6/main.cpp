#include<iostream>
#include<cstring>
using namespace std;

#include<iostream>
#include<cstring>

using namespace std;

class Task {
protected:
    char id[20];
public:
    Task(const char *id = "") {
        strcpy(this->id, id);
    }

    virtual int getBroj() = 0;

    virtual void print() = 0;

    char *getId() {
        return id;
    }
};

class TimedTask : public Task {
private:
    int time;
public:
    TimedTask(const char *id = "", int time = 0) : Task(id) {
        this->time = time;
    }

    int getBroj() {
        return time;
    }

    void print() {
        cout << "TT->" << id <<":"<< getBroj() << endl;
    }
};

class PriorityTask : public Task {
private:
    int priority;
public:
    PriorityTask(const char *id = "", int priority = 0) : Task(id) {
        this->priority = priority;
    }

    int getBroj() {
        return priority;
    }

    void print() {
        cout << "PT->" <<":"<< id << getBroj() << endl;
    }

};

bool operator==(Task *t1, Task &t2) {
    return (strcmp(t1->getId(), t2.getId()) && t1->getBroj() == t2.getBroj());
}

void sort(Task **tasks, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i]->getBroj() > tasks[j]->getBroj()) {
                Task *tmp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = tmp;
            }
        }
    }
}

void scheduleTimedTasks(Task **tasks, int n, int t) {
    sort(tasks, n);
    for (int i = 0; i < n; i++) {
        TimedTask *tt = dynamic_cast<TimedTask *>(tasks[i]);
        if (tt != 0) {
            if (tasks[i]->getBroj() < t) {
                tasks[i]->print();
            }
        }
    }
}

void schedulePriorityTasks(Task **tasks, int n, int p) {
    for (int i = 0; i < n; i++) {
        PriorityTask *pp = dynamic_cast<PriorityTask *>(tasks[i]);
        if (pp != 0) {
            if (tasks[i]->getBroj() < p) {
                tasks[i]->print();
            }
        }
    }
}
int main () {
    int testCase;
    int n;
    cin>>testCase;
    
    if (testCase==0){
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}
        
    	cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
    	schedulePriorityTasks(tasks,n,10);
        
    }
    else if (testCase==1) {
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}
        
    	
        cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
        scheduleTimedTasks(tasks,n,50);
    }
    else {
        TimedTask * tt1 = new TimedTask("11",10);
        TimedTask * tt2 = new TimedTask("11",11);
        TimedTask * tt3 = new TimedTask("11",11);
        PriorityTask * pp1 = new PriorityTask("aa",10);
        PriorityTask * pp2 = new PriorityTask("11",10);
        
        cout << (tt1==(*tt2))<<endl;
        cout << (tt2==(*tt3))<<endl;
        cout << (pp1==(*pp2))<<endl;
        cout << (pp2==(*tt1))<<endl;
    }
    
	return 0;
}
