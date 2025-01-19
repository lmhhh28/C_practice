#include<iostream>
using namespace std;

class Complex
{
    private:
        double reals;
        double imags;
    public:
        Complex():reals(1),imags(2){}
        Complex(double real,double imag):reals(real),imags(imag){}
        ~Complex(){}
        void Show();
        void Set(double real,double imag);
};

void Complex::Show()
{
    if(reals == 0 && imags == 0)
    {
        cout << 0 << endl;
    }
    else if(reals == 0)
    {
        cout << imags << 'i' << endl;
    }
    else if(imags == 0)
    {
        cout << reals << endl;
    }
    else if(imags > 0)
    {
        cout << reals << '+' << imags << 'i' << endl;
    }
    else
    {
        cout << reals << imags << 'i' << endl;
    }
}

void Complex::Set(double real,double imag)
{
    reals = real;
    imags = imag;
}

int main()
{
    Complex c1;
    cout<<"Show object c1:";
    c1.Show();
    double real,imag;
    cin>>real>>imag;
    Complex c2(real,imag);
    cout<<"Show object c2:";
    c2.Show();
    cin>>real>>imag;
    cout<<"Reset and Show object c1:";
    c1.Set(real,imag);
    c1.Show();
    return 0;
}