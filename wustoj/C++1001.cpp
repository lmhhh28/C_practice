#include<iostream>
using namespace std;

class Clock
{
    public:
        Clock(int hours,int mins,int seconds):hour(hours),min(mins),second(seconds){};
        Clock():hour(8),min(16),second(24){};
        ~Clock(){};
        void Show();
        void Set(int h,int m,int s);
    private:
        int hour,min,second;
};

void Clock::Show()
{
    cout << hour << ':' << min << ':' << second << endl;
}

void Clock::Set(int h,int m,int s)
{
    hour = h;
    min = m;
    second = s;
}

int main()
{
    Clock c1,c2(12,25,38);
    cout<<"Show object c1:";
    c1.Show();
    cout<<"Show object c2:";
    c2.Show();
    int h,m,s;
    cin>>h>>m>>s;
    cout<<"Reset and Show object c1:";
    c1.Set(h,m,s);
    c1.Show();
    cin>>h>>m>>s;
    cout<<"Reset and Show object c2:";
    c2.Set(h,m,s);
    c2.Show();
    return 0;
}