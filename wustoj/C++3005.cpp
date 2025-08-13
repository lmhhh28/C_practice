#include<iostream>
using namespace std;

class Point {
    private:
    int x, y;
    public:
    Point(int x, int y) : x(x), y(y) {
        cout << "Function #2 is called!" << endl;
    }
    Point() : x(0), y(0) {
        cout << "Function #1 is called!" << endl;
    }
    Point(const Point& obj) : x(obj.x), y(obj.y) {}
    void Show() {
        cout << '(' << x << ',' << y << ')' << endl;
        cout << "Function #3 is called!" << endl;
    }
};

class Rectangle : public Point {
    private:
    int width, height;
    public:
    Rectangle() : width(0), height(0), Point(6, 7) {
        cout << "Function #4 is called!" << endl;
    }
    Rectangle(int x, int y, int w, int h) : width(w), height(h), Point(x, y) {
        cout << "Function #5 is called!" << endl;
    }
    Rectangle(const Point& obj, int w, int h) : width(w), height(h), Point(obj) {
        cout << "Function #6 is called!" << endl;
    }
    Rectangle(int w, int h) : width(w), height(h), Point(100, 110) {
        cout << "Function #7 is called!" << endl;
    }
    Rectangle(const Point& obj) : width(10), height(11), Point(obj) {
        cout << "Function #8 is called!" << endl;
    }
    void Show() {
        cout << "Width=" << width << " Height=" << height << " Left_Up=";
        Point::Show();
        cout << "Function #9 is called!" << endl;
    }
};

int main()
{
    int x,y,w,h;
    cin>>x>>y>>w>>h;

    Point point0;
    cout<<"Point #0: ";           point0.Show();
    Point point1(x,y);
    cout<<"Point #1: ";           point1.Show();

    Rectangle rect0;
    cout<<"Rectangle #0: ";       rect0.Show();
    Rectangle rect1(x,y,w,h);
    cout<<"Rectangle #1: ";       rect1.Show();
    Rectangle rect2(point1,w,h);
    cout<<"Rectangle #2: ";       rect2.Show();
    Rectangle rect3(w,h);
    cout<<"Rectangle #3: ";       rect3.Show();
    Rectangle rect4(point1);
    cout<<"Rectangle #4: ";       rect4.Show();

    return 0;
}