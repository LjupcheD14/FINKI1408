#include <iostream>
#include <cstring>

using namespace std;

class NBAPlayer{
protected:
    char *ime;
    char tim[40];
    double poeni;
    double asistencii;
    double skokovi;
    void copi(const NBAPlayer & n){
        this->ime = new char[strlen(n.ime)+1];
        strcpy(this->ime,n.ime);
        strcpy(this->tim,n.tim);
        this->poeni=n.poeni;
        this->asistencii=n.asistencii;
        this->skokovi=n.skokovi;
    }
public:
    NBAPlayer(char *ime="", char *tim="", double poeni=0, double asistencii=0, double skokovi=0){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        strcpy(this->tim,tim);
        this->poeni=poeni;
        this->asistencii=asistencii;
        this->skokovi=skokovi;
    }
    NBAPlayer(const NBAPlayer & n){
        copi(n);
    }
    NBAPlayer &operator=(const NBAPlayer & n){
        if(this != &n){
            delete[] ime;
            copi(n);
        }
        return *this;
    }
    double rating(){
        return((poeni*0.45)+(asistencii*0.30)+(skokovi*0.25));
    }
    void print(){
        cout<<ime<<" - "<<tim<<endl;

        cout<<"Points: "<<poeni<<endl;

        cout<<"Assists: "<<asistencii<<endl;

        cout<<"Rebounds: "<<skokovi<<endl;

        cout<<"Rating: "<<rating()<<endl;
    }
    ~NBAPlayer(){
        delete[] ime;
    }
};

class AllStarPlayer : public NBAPlayer{
private:
    double poeniAllStar;
    double asistenciiAllStar;
    double skokoviAllStar;

    void copi(const AllStarPlayer &ap){
        this->poeniAllStar=ap.poeniAllStar;
        this->asistenciiAllStar=ap.asistenciiAllStar;
        this->skokoviAllStar=ap.skokoviAllStar;
    }
public:
    AllStarPlayer() : NBAPlayer()
    {
        poeniAllStar=0;
        asistenciiAllStar=0;
        skokoviAllStar=0;
    }

    AllStarPlayer(const NBAPlayer &p, double poeniAllStar, double asistenciiAllStar, double skokoviAllStar) : NBAPlayer(p){
        this->poeniAllStar=poeniAllStar;
        this->asistenciiAllStar=asistenciiAllStar;
        this->skokoviAllStar=skokoviAllStar;
    }
    AllStarPlayer( char *ime,  char *tim, double poeni, double asistencii, double skokovi, double poeniAllStar, double asistenciiAllStar, double skokoviAllStar) : NBAPlayer(ime,tim,poeni,asistencii,skokovi){
        this->poeniAllStar=poeniAllStar;
        this->asistenciiAllStar=asistenciiAllStar;
        this->skokoviAllStar=skokoviAllStar;
    }
    AllStarPlayer(const AllStarPlayer &ap) : NBAPlayer(ap){
        copi(ap);
    }
    AllStarPlayer&operator=(const AllStarPlayer &ap){
        if(this != &ap){
            delete[] ime;
            NBAPlayer::copi(ap);
            copi(ap);
        }
        return *this;
    }
    double allStarRating(){
        return ((poeniAllStar*0.3)+(asistenciiAllStar*0.4)+(skokoviAllStar*0.3));
    }
    double rating(){
        return(NBAPlayer::rating()+allStarRating())/2;
    }
    void print(){
        NBAPlayer::print();
        cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<rating()<<endl;
    }
};

int main() {

  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }

    delete [] players;
    delete [] asPlayers;
}
