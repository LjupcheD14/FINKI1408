#include<iostream>
#include<cstring>

using namespace std;

class Matrica{
private:
    float matrix[10][10];
    int broj;
public:
    Matrica(int n){
        this->broj=10;
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                this->matrix[i][j]=n;
            }
        }
    }
    Matrica(){
        this->broj=0;
    }
    Matrica &operator+(const Matrica &m){
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                this->matrix[i][j]+=m.matrix[i][j];
            }
        }
        return *this;
    }

    Matrica &operator-(const Matrica &m){
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                this->matrix[i][j]-=m.matrix[i][j];
            }
        }
        return *this;
    }

    Matrica &operator*(const Matrica &m){
        float tmp[broj][broj];
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                int zbir=0;
                for(int k=0;k<broj;k++){
                    zbir+=(this->matrix[i][k]*m.matrix[k][j]);
                }
                tmp[i][j]=zbir;
            }
        }
        for(int i=0;i<broj;i++){
            for(int j=0;j<broj;j++){
                this->matrix[i][j]=tmp[i][j];
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &in, Matrica &m){
        int br;
        in>>br;
        in>>br;
        m.broj=br;
        float tmp;
        for(int i=0;i<br;i++){
            for(int j=0;j<br;j++){
                in>>tmp;
                m.matrix[i][j]=tmp;
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &o, Matrica &m){
        for(int i=0;i<m.broj;i++){
            for(int j=0;j<m.broj;j++){
                o<<m.matrix[i][j]<<" ";
            }
            o<<endl;
        }
        return o;
    }
};

int main()
{
    Matrica A,B,C;
    cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;
}
