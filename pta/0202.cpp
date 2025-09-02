#include <iostream>
#include <iomanip>
#include <exception>

int main() {
    double a, b;
    try {
        std::cin >> a >> b;
        if(b == 0)  throw std::runtime_error("Error");
        else if(b < 0) {
            std::cout << a << '/' << '(' << b << ")=" << std::fixed << std::setprecision(2) << a / b << std::endl;
        } else {

        }
    } catch(std::exception& e) {
        std::cout << a << '/' << b << e.what() << std::endl;
    }
    return 0;
}