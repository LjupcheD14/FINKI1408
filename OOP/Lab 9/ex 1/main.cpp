#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class InvalidPassword {
private:
    char text[50];
public:
    InvalidPassword(const char *text = "") {
        strcpy(this->text, text);
    }

    void message() {
        cout << text << endl;
    }
};

class InvalidEmail {
private:
    char text[50];
public:
    InvalidEmail(const char *text = "") {
        strcpy(this->text, text);
    }

    void message() {
        cout << text << endl;
    }
};

class MaximumSizeLimit {
private:
    int n;
public:
    MaximumSizeLimit(int n = 0) {
        this->n = n;
    }

    void message() {
        cout << "You can't add more than " << n << " users." << endl;
    }

};

class User {
protected:
    char username[50];
    char password[50];
    char email[50];
public:
    User(const char *username = "", const char *password = "", const char *email = "") {
        strcpy(this->username, username);
        setPassword(password);
        setEmail(email);
    }

    virtual double popularity() = 0;

    void setPassword(const char *password = "") {
        int lowercase = 0, uppercase = 0, number = 0;
        for (int i = 0; i < strlen(password); i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                uppercase++;
            } else if (password[i] >= 'a' && password[i] <= 'z') {
                lowercase++;
            } else if (password[i] >= '0' && password[i] <= '9') {
                number++;
            }
        }
        if (!lowercase || !uppercase || !number) {
            throw InvalidPassword("Password is too weak.");
        }
        strcpy(this->password, password);
    }

    void setEmail(const char *email = "") {
        int counter = 0;
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                counter++;
            }
        }
        if (counter == 1) {
            strcpy(this->email, email);
        } else {
            throw InvalidEmail("Mail is not valid.");
        }
    }
};

class FacebookUser : public User {
private:
    int number_friends;
    int number_likes;
    int number_comments;
public:
    FacebookUser(const char *username = "", const char *password = "", const char *email = "", int number_friends = 0,
                 int number_likes = 0, int number_comments = 0) : User(username, password, email) {
        this->number_friends = number_friends;
        this->number_likes = number_likes;
        this->number_comments = number_comments;
    }

    double popularity() {
        return number_friends + (number_likes * 0.1) + (number_comments * 0.5);
    }

};

class TwitterUser : public User {
private:
    int number_followers;
    int number_tweets;
public:
    TwitterUser(const char *username = "", const char *password = "", const char *email="", int number_followers = 0,
                int number_tweets = 0) : User(username, password, email) {
        this->number_followers = number_followers;
        this->number_tweets = number_tweets;
    }

    double popularity() {
        return number_followers + (number_tweets * 0.5);
    }
};

class SocialNetwork {
private:
    User **users;
    int number;
    static int max_number;

    void copy(const SocialNetwork &sn) {
        number = sn.number;
        users = new User *[number];
        for (int i = 0; i < number; i++) {
            users[i] = sn.users[i];
        }
    }

public:
    SocialNetwork() {
        number = 0;
        users = new User *[number];
    }

    SocialNetwork(const SocialNetwork &sn) {
        copy(sn);
    }

    SocialNetwork &operator=(const SocialNetwork &sn) {
        if (this != &sn) {
            delete[]users;
            copy(sn);
        }
        return *this;
    }

    SocialNetwork &operator+=(User *user) {
        if (number == max_number) {
            throw (MaximumSizeLimit(max_number));
        }
        User **tmp = new User *[number + 1];
        for (int i = 0; i < number; i++) {
            tmp[i] = users[i];
        }
        tmp[number++] = user;
        delete[]users;
        users = tmp;
        return *this;
    }

    double avgPopularity() {
        double total = 0;
        for (int i = 0; i < number; i++) {
            total += users[i]->popularity();
        }
        return total / number;
    }

    static void changeMaximumSize(int num){
        SocialNetwork::max_number=num;
    }
};

int SocialNetwork::max_number=5;



int main() {

    SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i = 0; i < n; ++i) {
        cin >> username;
        cin >> password;
        cin >> email;
        cin >> userType;
        if (userType == 1) {
            int friends;
            int likes;
            int comments;
            cin >> friends >> likes >> comments;

            // TODO: Try-catch
            try{
                User *u = new FacebookUser(username, password, email, friends, likes, comments);
                network += u;
            }
            catch (InvalidPassword &ip){
                ip.message();
            }
            catch(InvalidEmail &ie){
                ie.message();
            }
            catch (MaximumSizeLimit &sl){
                sl.message();
            }

        } else {
            int followers;
            int tweets;
            cin >> followers >> tweets;

            // TODO: Try-catch
            try{
                User *u = new TwitterUser(username, password, email, followers, tweets);
                network += u;
            }
            catch (InvalidPassword &ip){
                ip.message();
            }
            catch(InvalidEmail &ie){
                ie.message();
            }
            catch (MaximumSizeLimit &sl){
                sl.message();
            }

        }

    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;

    // TODO: Try-catch
    try {
        User *u = new TwitterUser(username, password, email, followers, tweets);
        network += u;
    }
    catch (InvalidPassword &ip){
        ip.message();
    }
    catch(InvalidEmail &ie){
        ie.message();
    }
    catch (MaximumSizeLimit &sl){
        sl.message();
    }
    
    cout << network.avgPopularity();
}
