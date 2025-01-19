#include<iostream>
using namespace std;

class Rectangle
{
    private:
        double width;
        double height;
    public:
        Rectangle():width(2),height(2){}
        Rectangle(double w,double h):width(w),height(h){}
        ~Rectangle(){}
        double GetWidth(){return width;}
        double GetHeight(){return height;};
        double Perimeter(){return 2 * (width + height);}
        double Area(){return width * height;}
        void Set(double w,double h);
};

void Rectangle::Set(double w,double h)
{
    width = w;
    height = h;
}

int main()
{
    Rectangle rect1;
    cout<<"Show object rect1:"<<endl;
    cout<<"    width="<<rect1.GetWidth()<<endl;
    cout<<"    height="<<rect1.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
    cout<<"    Area="<<rect1.Area()<<endl;
    double w,h;
    cin>>w>>h;
    Rectangle rect2(w,h);
    cout<<"Show object rect2:"<<endl;
    cout<<"    width="<<rect2.GetWidth()<<endl;
    cout<<"    height="<<rect2.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect2.Perimeter()<<endl;
    cout<<"    Area="<<rect2.Area()<<endl;
    cin>>w>>h;
    cout<<"Reset and Show object rect1:"<<endl;
    rect1.Set(w,h);
    cout<<"    width="<<rect1.GetWidth()<<endl;
    cout<<"    height="<<rect1.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
    cout<<"    Area="<<rect1.Area()<<endl;
    return 0;
}