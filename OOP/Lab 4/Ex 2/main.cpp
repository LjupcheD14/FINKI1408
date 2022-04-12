#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    pdf, exe, txt
};

class File {
private:
    char *fileName;
    char *ownerName;
    int size;
    Extension extension;

    void freeMemory() {
        delete[] fileName;
        delete[] ownerName;
    }

    void copy(const File &f) {
        this->fileName = new char[strlen(f.fileName) + 1];
        strcpy(this->fileName, f.fileName);
        this->ownerName = new char[strlen(f.ownerName) + 1];
        strcpy(this->ownerName, f.ownerName);
        this->size = f.size;
        this->extension = f.extension;
    }

public:
    File() {
        this->fileName = new char[0];
        this->ownerName = new char[0];
        this->size = 0;
    }

    File(char *_fileName, char *_ownerName, int _size, Extension _extension) {
        this->fileName = new char[strlen(_fileName) + 1];
        strcpy(this->fileName, _fileName);
        this->ownerName = new char[strlen(_ownerName) + 1];
        strcpy(this->ownerName, _ownerName);
        this->size = _size;
        this->extension = _extension;
    }

    File(const File &f) {
        copy(f);
    }

    ~File() {
        freeMemory();
    }

    File &operator=(const File &f) {
        if (this != &f) {
            freeMemory();
            copy(f);
        }
        return *this;
    }

    void print() {
        char ext[4];
        if (this->extension == 0) strcpy(ext, "pdf");
        if (this->extension == 1) strcpy(ext, "txt");
        if (this->extension == 2) strcpy(ext, "exe");
            cout<<"File name: "<<this->fileName<<"."<<ext<<endl;
            cout<<"File owner: "<<this->ownerName<<endl;
            cout<<"File size: "<<this->size<<endl;
    }

    bool equals(const File &that) {
        return this->extension == that.extension && !strcmp(this->fileName, that.fileName) &&
               !strcmp(this->ownerName, that.ownerName);
    }

    bool equalsType(const File &that) {
        return this->extension == that.extension && !strcmp(this->fileName, that.fileName);
    }
};

class Folder {
private:
    char *name;
    int number;
    File *files;

    void freeMemory() {
        delete[] name;
        delete[] files;
    }

public:
    Folder() {
        this->name = new char[0];
        this->number = 0;
        this->files = new File[0];
    }

    Folder(const char *_name) {
        this->name = new char[strlen(_name) + 1];
        strcpy(this->name, _name);
        this->number = 0;
        this->files = new File[0];
    }

    ~Folder() {
        freeMemory();
    }

    void print() {
        cout << "Folder name: " << this->name << endl;
        for (int i = 0; i < number; i++) {
            this->files[i].print();
        }
    }

    void remove(const File &f) {
        int removeNum = this->number;
        for (int i = 0; i < this->number; i++) {
            if (this->files[i].equals(f)) {
                removeNum - i;
                break;
            }
        }
        if (removeNum == this->number)return;
        this->number--;
        for (int i = removeNum; i < this->number; i++) {
            this->files[i] = this->files[i + 1];
        }
    }

    void add(const File &f) {
        File *tmp = new File[this->number + 1];
        for (int i = 0; i < this->number; i++) {
            tmp[i] = this->files[i];
        }
        tmp[this->number++] = f;
        delete[]files;
        this->files = tmp;
    }

};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
