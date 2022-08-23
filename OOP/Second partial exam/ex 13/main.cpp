#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Image
{
protected:
    char *imeSlika;
    char sopstvenik[50];
    int sirina;
    int visina;
public:
    Image(const char *imeSlika="untitled",const char *sopstvenik="unknown",int sirina=800,int visina=800)
    {
        this->imeSlika = new char [strlen(imeSlika)+1];
        strcpy(this->imeSlika,imeSlika);
        strcpy(this->sopstvenik,sopstvenik);
        this->sirina=sirina;
        this->visina=visina;
    }
    virtual int fileSize()
    {
        return visina*sirina*3;
    }
    friend ostream&operator<<(ostream &out,Image &i)
    {
        return out<<i.imeSlika<<" "<<i.sopstvenik<<" "<<i.fileSize()<<endl;
    }
    friend ostream&operator<<(ostream &out,Image *i)
    {
        return out<<i->imeSlika<<" "<<i->sopstvenik<<" "<<i->fileSize()<<endl;
    }
    bool operator >(Image &i)
    {
        return fileSize() > i.fileSize();
    }
};
class TransparentImage : public Image
{
private:
    bool trans;
public:
    TransparentImage(const char *imeSlika="untitled",const char *sopstvenik="unknown",int sirina=800,int visina=800,bool trans=true) : Image(imeSlika,sopstvenik,sirina,visina)
    {
        this->trans=trans;
    }
    int fileSize()
    {
        if(trans == true)
        {
            return sirina*visina*4;
        }
        else
        {
            return sirina*visina + (sirina*visina)/8;
        }
    }
};
class Folder
{
private:
    char ime[255];
    char sopstvenik[50];
    Image *niza[100];
    int broj;
public:
    Folder(const char *ime="",const char *sopstvenik="unknown")
    {
        strcpy(this->ime,ime);
        strcpy(this->sopstvenik,sopstvenik);
        this->broj = 0;
    }
    int folderSize() const
    {
        int total=0;
        for(int i=0;i<broj;i++)
        {
            total+=niza[i]->fileSize();
        }
        return total;
    }
    Image *getMaxFile()
    {
        Image *temp = niza[0];
        for(int i=1;i<broj;i++)
        {
            if((*niza[i]) > *temp)
            {
                temp=niza[i];
            }
        }
        return temp;
    }
    Folder&operator+=(Image &i)
    {
        niza[broj++] = &i;
        return *this;
    }
    friend ostream&operator<<(ostream &out,const Folder &f)
    {
        out<<f.ime<<" "<<f.sopstvenik<<endl;
        out<<"--"<<endl;
        for(int i=0;i<f.broj;i++)
        {
            out<<f.niza[i];
        }
        out<<"--"<<endl;
        out<<"Folder size: "<<f.folderSize();
        return out;
    }
    Image*operator[](int index)
    {
        if(index>broj)
        {
            return NULL;
        }
        return niza[index];
    }
};
Folder max_folder_size(Folder *folders,int n)
{
    Folder temp=folders[0];
    for(int i=1;i<n;i++)
    {
        if(folders[i].folderSize() > temp.folderSize())
        {
            temp=folders[i];
        }
    }
    return temp;
}
int main()
{
  int tc; // Test Case
 
    char name[255];
    char user_name[51];
    int w, h;
    bool tl;
 
    cin >> tc;
 
    if (tc==1){
      // Testing constructor(s) & operator << for class File
 
      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;
 
 
      Image f1;
 
      cout<< f1;
 
      Image f2(name);
      cout<< f2;
 
      Image f3(name, user_name);
      cout<< f3;
 
      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;
 
      TransparentImage tf1;
      cout<< tf1;
 
      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;
 
      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;
 
      Folder dir(name, user_name);
 
      Image * f;
      TransparentImage *tf;
 
      int sub, fileType;
 
      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;
 
        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder
 
      cin >> name;
      cin >> user_name;
 
      Folder dir(name, user_name);
 
      Image* f;
      TransparentImage* tf;
 
      int sub, fileType;
 
      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;
 
        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder
 
      cin >> name;
      cin >> user_name;
 
      Folder dir(name, user_name);
 
      Image* f;
      TransparentImage* tf;
 
      int sub, fileType;
 
      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;
 
        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
 
      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;
 
      Folder dir_list[10];
 
      Folder dir;
      cin >> folders_num;
 
      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);
 
 
        Image* f;
        TransparentImage *tf;
 
        int sub, fileType;
 
        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;
 
          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }
 
      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
}
