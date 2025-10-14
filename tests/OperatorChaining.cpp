#include <iostream>
#include <utility>
using namespace std;

class Complex {
	private:
		int real,imag;
	public:
		Complex() : real(0), imag(0) {}
        Complex(int reals,int imags) : real(reals), imag(imags) {}
        Complex(const Complex& obj) : real(obj.real), imag(obj.imag) {
            cout << "Copy Constructor was Called." << endl;
        }
        Complex(Complex&& obj) noexcept : real(obj.real), imag(obj.imag) {
            cout << "Move Constructor was Called." << endl;
        }
		Complex& addSelf(const Complex& obj);
        friend Complex addOther(const Complex& obj_1, const Complex& obj_2);
		void showCase();
}; 

Complex& Complex::addSelf(const Complex& obj) {
	real += obj.real;
	imag += obj.imag;
	return *this;
} 

Complex addOther(const Complex& obj_1, const Complex& obj_2) {
    Complex temp(0,0);
    temp.addSelf(obj_1).addSelf(obj_2);
    return move(temp);
}

void Complex::showCase() {
	cout << real << '+' << imag << 'i' << endl;
}

int main(void) {
	Complex c_1(1,1);
	c_1.showCase();
	Complex c_2(c_1);Complex c_3(c_1);Complex c_4(c_1);
	c_1.addSelf(c_2).addSelf(c_3).addSelf(c_4).showCase();
    Complex c_5 = addOther(c_1,c_1);
    c_5.showCase();
    return 0;
}