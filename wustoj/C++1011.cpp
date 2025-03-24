#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Book {
    private:
        char* title;
        char* author;
        double price;
        void init() {
            title = new char[40];
            author = new char[40];
        }
    public:
        Book() {
            init();
            Set("NULL", "NONE", 0); 
        }
        Book(char* titles, char* authors, double prices) {
            init();
            Set(titles, authors, prices);
        }
        void Set(char* titles, char* authors, double prices) {
            strcpy(title, titles);
            strcpy(author, authors);
            price = prices;
        }
        void Set() {
            Set("高等数学(第七版)上册", "同济大学数学系", 37.7);
        }
        char* GetTitle() {
            return title;
        }
        char* GetAuthor() {
            return author;
        }
        double GetPrice() {
            return price;
        }
        void Show() {
            cout<<GetTitle()<<"，"<<GetAuthor()<<"，"<<GetPrice()<<endl;
        }
};

int main()
{
    cout<<fixed<<setprecision(2);
    Book b1;
    cout<<"Show object b1:";
    cout<<b1.GetTitle()<<"，"<<b1.GetAuthor()<<"，"<<b1.GetPrice()<<endl;
    char title[40],author[40];
    double price;
    cin>>title>>author>>price;
    Book b2(title,author,price);
    cout<<"Show object b2:";
    cout<<b2.GetTitle()<<"，"<<b2.GetAuthor()<<"，"<<b2.GetPrice()<<endl;
    cin>>title>>author>>price;
    cout<<"Reset and Show object b1:";
    b1.Set(title,author,price);
    b1.Show();
    cout<<"Reset and Show object b2:";
    b2.Set();
    b2.Show();
    return 0;
}