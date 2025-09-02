#include <iostream>
#include <vector>
#include <exception>
using namespace std;

struct Int {
    vector<int> num;
    string ibuffer;
    
};

struct Double {
    vector<int> inte, floa;
    string ibuffer;
    Double();
    Double(double);
    Double(const string&);
    Double(const Double&);
    void trans();
    friend istream& operator>>(istream&, Double&);
    friend ostream& operator<<(ostream&, const Double&);
    friend Double operator+(const Double&, const Double&);
    friend Double operator-(const Double&, const Double&);
};