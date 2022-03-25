#include<iostream>
#include<cstring>

using namespace std;


class Category {
private:
    char name[50] = "unnamed";
public:
    Category() {
        strcpy(name, "unnamed");
    }

    Category(char *_name) {
        strcpy(name, _name);
    }

    void print() {
        cout << "Category: " << name << endl;
    }

};

class NewsArticle {
private:
    Category category;
    char title[30] = "untitled";
public:
    NewsArticle() {
        strcpy(title, "untitled");
    }

    NewsArticle(Category _category, char *_title) {
        category = _category;
        strcpy(title, _title);
    }

    NewsArticle(Category _category) {
        category = _category;
    }

    void print() {
        cout << "Article title: " << title << endl;
        category.print();
    }

};

class FrontPage {
private:
    NewsArticle newarticle;
    float price;
    int editionNumber = 0;
public:
    FrontPage() {
        price = 0;
        editionNumber = 0;
    }

    FrontPage(NewsArticle _newsarticle, float _price, float _editionNumber) {
        newarticle = _newsarticle;
        price = _price;
        editionNumber = _editionNumber;
    }

    FrontPage(NewsArticle _newsarticle, float _price){
        newarticle = _newsarticle;
        price = _price;
    }

    void print() {
        cout << "Price: " << price << ", Edition number: " << editionNumber << endl;
        newarticle.print();
    }

};


int main() {
    char categoryName[20];
    char articleTitle[30];
    float price;
    int editionNumber;

    int testCase;
    cin >> testCase;


    if (testCase == 1) {
        int iter;
        cin >> iter;
        while (iter > 0) {
            cin >> categoryName;
            cin >> articleTitle;
            cin >> price;
            cin >> editionNumber;
            Category category(categoryName);
            NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber);
            frontPage.print();
            iter--;
        }
    } else if (testCase == 2) {
        cin >> categoryName;
        cin >> price;
        cin >> editionNumber;
        Category category(categoryName);
        NewsArticle article(category);
        FrontPage frontPage(article, price, editionNumber);
        frontPage.print();
    }// test case 3
    else if (testCase == 3) {
        cin >> categoryName;
        cin >> articleTitle;
        cin >> price;
        Category category(categoryName);
        NewsArticle article(category, articleTitle);
        FrontPage frontPage(article, price);
        frontPage.print();
    } else {
        FrontPage frontPage = FrontPage();
        frontPage.print();
    }
    return 0;
}
