#include<iostream>
#include <windows.h>
using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point() : x(19), y(210) {
            cout << "Function #1 is called!" << endl;
        }
        Point(int px, int py) : x(px), y(py) {
            cout << "Function #2 is called!" << endl;
        }
        Point(const Point& obj) : x(obj.x), y(obj.y) {
            cout << "Function #0 is called!" << endl;
        }
        void Show() {
            cout << '(' << x << ',' << y << ')' << endl;
            cout << "Function #3 is called!" << endl;
        }
};

class Circle : public Point {
    private:
        int r;
    public:
        Circle() : r(135), Point() {
            cout << "Function #4 is called!" << endl;
        }
        Circle(int px, int py) : r(777), Point(px, py) {
            cout << "Function #5 is called!" << endl;
        }
        Circle(int px, int py, int pr) : r(pr), Point(px, py) {
            cout << "Function #6 is called!" << endl;
        }
        Circle(const Point& p, int pr) : r(pr), Point(p) {
            cout << "Function #7 is called!" << endl;
        }
        Circle(const Point& p) : r(111), Point(p) {
            cout << "Function #8 is called!" << endl;
        }
        Circle(int pr) : r(pr), Point(5, 20) {
            cout << "Function #9 is called!" << endl;
        }
        void Show() {
            cout << "Radius=" << r << ',' << "Center=";
            Point::Show();
            cout << "Function #10 is called!" << endl;
        }
}; 

int main()
{
    DWORD start_time = GetTickCount();
    int x = 1,y = 2,r = 3;
    Point p0;
    cout<<"[Point #0] "; p0.Show();
    Circle c0;
    cout<<"[Circle #0]";  c0.Show();
    Circle c1(x,y);
    cout<<"[Circle #1]";  c1.Show();
    Circle c2(x,y,r);
    cout<<"[Circle #2]";  c2.Show();
    Circle c3(p0,r);
    cout<<"[Circle #3]";  c3.Show();
    Circle c4(p0);
    cout<<"[Circle #4]";  c4.Show();
    Circle c5(r);
    cout<<"[Circle #5]";  c5.Show();
    DWORD end_time = GetTickCount();
    cout << "time: " << (end_time - start_time) << "ms." << endl;
    // system("pause");
    return 0;
}