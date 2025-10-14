#include <iostream>
using namespace std;
class Complex {
	private:
		int real, imag;
	public:
		Complex(int reals, int imags) : real(reals), imag(imags) {}
		~Complex() {}
		friend Complex operator + (const Complex& obj_1, const Complex& obj_2);
		void showCase() {
			cout << real << '+' << imag << 'i' << endl;
		}
		Complex& operator = (const Complex& obj) {
			if(this != &obj) {
                real = obj.real;
                imag = obj.imag;
                return *this;
            }
		}
        Complex& operator += (const Complex& obj) {
        	real += obj.real;
        	imag += obj.imag;
        	return *this;
        }
};

Complex operator + (const Complex& obj_1, const Complex& obj_2) {
	return Complex(obj_1.real + obj_2.real, obj_1.imag + obj_2.imag);
}

int main() {
	Complex c_1(1, 1), c_2(2, 2), c_3(3, 3);
	(c_1 += c_2 + c_3).showCase();
    (c_1 = c_1).showCase();
}