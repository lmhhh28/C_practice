#include<iostream>
using namespace std;

class Time {
    private:
        int hour,minute,second;
    public:
        Time() {
            Set(1, 2, 3);
            // cout << "默认构造函数" << endl;
        }
        Time(int hours, int minutes, int seconds) {
            Set(hours, minutes, seconds);
            // cout << "有参构造函数" << endl;
        }
        Time(Time& obj) : hour(obj.hour), minute(obj.minute), second(obj.second) {
            // cout << "拷贝构造函数" << endl;
        }
        Time(Time&& obj) noexcept : hour(obj.hour), minute(obj.minute), second(obj.second) {
            // cout << "移动构造函数" << endl;
        }
        ~Time() {
            // cout << "析构函数" << endl;
        };
        void Set(int hours, int minutes, int seconds) {
            hour = hours;
            minute = minutes;
            second = seconds;
        }
        friend ostream& operator << (ostream& os, const Time& time);
        friend Time operator + (Time& time, int n);
        friend Time operator - (Time& time, int n);
        friend int operator - (Time& t_1, Time& t_2);
        Time& operator = (Time&& time) noexcept {
            if(this != &time) {
                second = time.second;
                minute = time.minute;
                hour = time.hour;
            }
            return *this;
        };
};

ostream& operator << (ostream& os, const Time& time) {
    os << time.hour << ':' << time.minute << ':' << time.second;
    return os;
}

Time operator + (Time& time, int n) {
    Time temp(time);
    temp.second += n;
    temp.minute += temp.second / 60;
    temp.second %= 60;
    temp.hour += temp.minute / 60;
    temp.minute %= 60;
    temp.hour %= 24;
    return move(temp); 
}

Time operator - (Time& time, int n) {
    Time temp(time);
    temp = time + (- n);
    if(temp.second < 0) {
        temp.minute --;
        temp.second += 60;
    }
    if(temp.minute < 0) {
        temp.hour --;
        temp.minute +=60;
    }
    if(temp.hour < 0) {
        temp.hour += 24;
    }
    return move(temp);
}

int operator - (Time& t_1, Time& t_2) {
    return (t_1.hour - t_2.hour) * 3600 + (t_1.minute - t_2.minute) * 60 + t_1.second - t_2.second;
}

int main()
{
    Time t1;
    cout<<"Show object t1:"<<t1<<endl;
    int hour,minute,second;
    cin>>hour>>minute>>second;
    Time t2(hour,minute,second);
    cout<<"Show object t2:"<<t2<<endl;
    cin>>hour>>minute>>second;
    t1.Set(hour,minute,second);
    cout<<"Reset and Show object t1:"<<t1<<endl;
    int n;
    n=t2-t1;
    cout<<t2<<"-"<<t1<<"="<<n<<"s"<<endl;
    cin>>n;
    cout<<t1<<"+"<<n<<"s=";
    t2=t1+n;
    cout<<t2<<endl;
    cout<<t1<<"-"<<n<<"s=";
    t1=t1-n;
    cout<<t1<<endl;
    return 0;
}