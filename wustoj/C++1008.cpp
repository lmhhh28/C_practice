#include<iostream>
#include<cmath>
using namespace std;

class Line {
    private:
        double x1,y1,x2,y2;
        double lenth;
    public:
        Line() : x1(0), y1(0), x2(0), y2(0), lenth(0) {}
        Line(int x1s, int y1s, int x2s, int y2s) : x1(x1s), y1(y1s), x2(x2s), y2(y2s) {
            lenth = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
        void Show() {
            cout << '(' << x1 << ',' << y1 << ')' << "--" << '(' << x2 << ',' << y2 << ')' << "length=" << lenth << endl;
        }
        void Set(int x1s, int y1s, int x2s, int y2s) {
            x1 = x1s;
            y1 = y1s;
            x2 = x2s;
            y2 = y2s;
            lenth = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
        void Set() {
            x1 = 1;
            y1 = 5;
            x2 = 8;
            y2 = 4;
            lenth = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }
};

int main()
{
    Line L1;
    cout<<"Show object L1:";
    L1.Show();
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Line L2(x1,y1,x2,y2);
    cout<<"Show object L2:";
    L2.Show();
    cin>>x1>>y1>>x2>>y2;
    cout<<"Reset and Show object L1:";
    L1.Set(x1,y1,x2,y2);
    L1.Show();
    cout<<"Reset and Show object L2:";
    L2.Set();
    L2.Show();
    return 0;
}