#include <iostream>
#include <iomanip>
#define first 0.53
#define sec 0.58
int main() {
    double elec;
    std::cin >> elec;
    if(elec < 0)    std::cout << "Invalid Value!" << std::endl;
    else {
        double num = elec >= 50 ? (50 * first + (elec - 50) * sec) : (elec * first);
        std::cout << std::fixed << std::setprecision(2) << "cost = " << num << std::endl;
    }
    return 0;
}