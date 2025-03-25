#include<iostream>
using namespace std;
inline int gcd(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl; 
}

inline int gcd(int a, int b) {
	return b > 0 ? gcd(b, a % b) : a;
}
