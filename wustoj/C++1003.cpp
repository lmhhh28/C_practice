#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14;

class Circle
{
    private:
        double radius;
    public:
        Circle():radius(10.0){}
        Circle(double r):radius(r){}
        ~Circle(){};
        double Get();
        double Circumference();
        double Square();
        void Set(double r);
};

double Circle::Get()
{
    return radius;
}

double Circle::Circumference()
{
    return 2 * PI * radius;
}

double Circle::Square()
{
    return PI * radius * radius;
}

void Circle::Set(double r)
{
    radius = r;
}

int main()
{
    Circle c1;
    cout<<"Show object c1:"<<endl;
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    double r;
    cin>>r;
    Circle c2(r);
    cout<<"Show object c2:"<<endl;
    cout<<"    radius="<<c2.Get()<<endl;
    cout<<"    Circumference="<<c2.Circumference()<<endl;
    cout<<"    Square="<<c2.Square()<<endl;
    cin>>r;
    cout<<"Reset and Show object c1:"<<endl;
    c1.Set(r);
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    return 0;
}