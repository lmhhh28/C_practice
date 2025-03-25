#include<iostream>
#include<iomanip>
using namespace std;

class Circle {
    private:
        static constexpr double pi = 3.14159;
        double radius, area;
    public:
        Circle() : radius(0), area(0) {}
        Circle(double r, double areas) : radius(r), area(areas) {}
        Circle(Circle&& circle) noexcept : radius(circle.radius), area(circle.area) {}
        ~Circle() {}
        Circle& operator=(Circle&& other);
        double GetArea() { return area; }
        friend istream& operator>>(istream& in, Circle& circle);
        friend ostream& operator<<(ostream& os, Circle& circle);
        friend Circle operator+(Circle& c_1, Circle& c_2);
};

Circle& Circle::operator=(Circle&& other) {
    if(this != &other) {
        radius = other.radius;
        area = other.area;
    }
    return *this;
}

istream& operator>>(istream& in, Circle& circle) {
    in >> circle.radius;
    circle.area = circle.radius * circle.radius * circle.pi;
    return in;
}

ostream& operator<<(ostream& os, Circle& circle) {
    return os << "radius=" << circle.radius << ",area=" << circle.area;
}

Circle operator+(Circle& c_1, Circle& c_2) {
    return Circle(c_1.radius + c_2.radius, c_1.area + c_2.area);
}

int main()
{
    cout<<fixed<<showpoint<<setprecision(5);
    int n,i;
    cin>>n;
    Circle *c=new Circle[n+1];
    for(i=1;i<=n;i++)
        cin>>c[i];
    for(i=0;i<=n;i++)
        cout<<i<<":"<<c[i]<<endl;
    for(i=1;i<=n;i++)
        c[0]=c[0]+c[i];
    cout<<"total area="<<c[0].GetArea()<<endl;
    delete[] c;
    return 0;
}