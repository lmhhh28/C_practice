#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    cout << fixed << setprecision(5);
    if(delta > 0) {
        cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << ";";
        cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
    } else if(delta == 0) {
        cout << "x1=x2=" << (-b / (2 * a) < 1e-10 ? 0.0 : -b / (2 * a)) << endl;
    } else {
        cout << "x1=" << (abs(-b / (2 * a)) < 1e-10 ? 0.0 : -b / (2 * a)) << "+" << sqrt(-delta) / (2 * a) << "i;";
        cout << "x2=" << (abs(-b / (2 * a)) < 1e-10 ? 0.0 : -b / (2 * a)) << "-" << sqrt(-delta) / (2 * a) << "i" << endl;
    }
    return 0;
}