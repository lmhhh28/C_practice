#include<iostream>
using namespace std;

class CTime {
    private:
    int hour, minute, second;
    public:
        CTime() : hour(9), minute(10), second(11) {
            cout << "Function #1 is called!" << endl;
        }
        CTime(int th, int tm, int ts) : hour(th), minute(tm), second(ts) {
            cout << "Function #2 is called!" << endl;
        }
        CTime(const CTime& obj) : hour(obj.hour), minute(obj.minute), second(obj.second) {
            cout << "Function #0 is called!" << endl;
        }
        void Show() {
            cout << hour << ':' << minute << ':' << second << endl;
            cout << "Function #3 is called!" << endl;
        }
};

class CDate : public CTime {
    private:
        int year, month, day;
    public:
        CDate() : year(2023), month(4), day(5), CTime() {
            cout << "Function #4 is called!" << endl;
        }
        CDate(int dy, int dm, int dd) : year(dy), month(dm), day(dd), CTime() {
            cout << "Function #5 is called!" << endl;
        }
        CDate(int dy, int dm, int dd, int th, int tm, int ts) : year(dy), month(dm), day(dd), CTime(th, tm, ts) {
            cout << "Function #6 is called!" << endl;
        }
        CDate(int dy, int dm, int dd, const CTime& t) : year(dy), month(dm), day(dd), CTime(t) {
            cout << "Function #7 is called!" << endl;
        }
        CDate(const CTime& t) : year(2000), month(12), day(31), CTime(t) {
            cout << "Function #8 is called!" << endl;
        }
        void Show() {
            cout << year << '-' << month << '-' << day << ' ';
            CTime::Show();
            cout << "Function #9 is called!" << endl;
        }
};

int main()
{
    int dy,dm,dd,th,tm,ts;
    cin>>dy>>dm>>dd>>th>>tm>>ts;
    CTime t1;
    cout<<"[T1]";    t1.Show();
    CDate d1;
    cout<<"[D1]";    d1.Show();
    CDate d2(dy,dm,dd);
    cout<<"[D2]";    d2.Show();
    CDate d3(dy,dm,dd,th,tm,ts);
    cout<<"[D3]";    d3.Show();
    CDate d4(dy,dm,dd,t1);
    cout<<"[D4]";    d4.Show();
    CDate d5(t1);
    cout<<"[D5]";    d5.Show();
    return 0;
}