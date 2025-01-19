#include<iostream>
using namespace std;

class Date
{
    private:
        int year,month,day;
    public:
        Date():year(2015),month(5),day(20){}
        Date(int years,int months,int days):year(years),month(months),day(days){}
        ~Date(){};
        int GetYear(){return year;}
        int GetMonth(){return month;}
        int GetDay(){return day;}
        void Set(int y,int m,int d);
        void Set();
        void Show();
};

void Date::Set(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::Set()
{
    year = 2050;
    month = 12;
    day = 1;
}

void Date::Show()
{
    cout << year << '-' << month << '-' << day << endl;
}

int main()
{
    Date d1;
    cout<<"Show object d1:";
    cout<<d1.GetYear()<<"-"<<d1.GetMonth()<<"-"<<d1.GetDay()<<endl;
    int y,m,d;
    cin>>y>>m>>d;
    Date d2(y,m,d);
    cout<<"Show object d2:";
    cout<<d2.GetYear()<<"-"<<d2.GetMonth()<<"-"<<d2.GetDay()<<endl;
    cin>>y>>m>>d;
    cout<<"Reset and Show object d1:";
    d1.Set(y,m,d);
    d1.Show();
    cout<<"Reset and Show object d2:";
    d2.Set();
    d2.Show();
    return 0;
}