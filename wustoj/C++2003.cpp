#include<iostream>
using namespace std;

class Complex {
    private:
        double re, im;
    public:
        Complex() : re(0), im(0) {}
        Complex(double res, double ims) : re(res), im(ims) {}
        void Set(double res, double ims) {
            re = res;
            im = ims;
        }
        friend ostream& operator<<(ostream &os, Complex complex);
        friend Complex operator+(Complex& c_1, Complex& c_2);
        friend Complex operator-(Complex& c_1, Complex& c_2);
        friend Complex operator*(Complex& c_1, Complex& c_2);
};

ostream& operator<<(ostream &os, Complex complex) {
    if(complex.re == 0) {
        if(complex.im == 0) {
            os << 0;
        } else if(complex.im == 1) {
            os << 'i';
        } else if(complex.im == -1) {
            os << "-i";
        } else {
            os << complex.im << 'i';
        }
    } else {
        if(complex.im == 0) {
            os << complex.re;
        } else if(complex.im == 1) {
            os << complex.re << '+' << 'i';
        } else if(complex.im == -1) {
            os << complex.re << "-i";
        } else if(complex.im > 0) {
            os << complex.re << '+' << complex.im << 'i';
        } else {
            os << complex.re << complex.im << 'i';
        }
    }
    return os;
}

Complex operator+(Complex& c_1, Complex& c_2) {
    return Complex(c_1.re + c_2.re, c_1.im + c_2.im);
}

Complex operator-(Complex& c_1, Complex& c_2) {
    return Complex(c_1.re - c_2.re, c_1.im - c_2.im);
}

Complex operator*(Complex& c_1, Complex& c_2) {
    return Complex(c_1.re * c_2.re - c_1.im * c_2.im, c_1.re * c_2.im + c_2.re * c_1.im);
}


int main()
{
    Complex c1;
    cout<<"Show object c1:"<<c1<<endl;
    double re,im;
    cin>>re>>im;
    Complex c2(re,im);
    cout<<"Show object c2:"<<c2<<endl;
    cin>>re>>im;
    c1.Set(re,im);
    cout<<"Reset and Show object c1:"<<c1<<endl;
    Complex c3;
    c3=c1+c2;
    cout<<c1<<" + "<<c2<<" = "<<c3<<endl;
    c3=c1-c2;
    cout<<c1<<" - "<<c2<<" = "<<c3<<endl;
    c3=c1*c2;
    cout<<c1<<" * "<<c2<<" = "<<c3<<endl;
    return 0;
}