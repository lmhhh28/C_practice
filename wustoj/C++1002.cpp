#include<iostream>
using namespace std;

class Point
{
    private:
        int x,y;
    public:
        Point(int x_,int y_):x(x_),y(y_){};
        Point():x(10),y(16){};
        ~Point(){};
        void Show();
        void Set(int x_,int y_);
};

void Point::Show()
{
    cout << '(' << x << ',' << y << ')' << endl;
}

void Point::Set(int x_,int y_)
{
    x = x_;
    y = y_;
}

int main()
{
    Point p1,p2(20,100);
    cout<<"Show object p1:";
    p1.Show();
    cout<<"Show object p2:";
    p2.Show();
    int x,y;
    cin>>x>>y;
    cout<<"Reset and Show object p1:";
    p1.Set(x,y);
    p1.Show();
    cin>>x>>y;
    cout<<"Reset and Show object p2:";
    p2.Set(x,y);
    p2.Show();
    return 0;
}