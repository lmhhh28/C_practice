#include <iostream>
using namespace std;
int main() {
    int min, max, first, second;
    cin >> min >> max >> first >> second;
    if(first >= min && second >= min) {
        cout << first << "-Y " << second << "-Y" << endl;
        cout << "huan ying ru guan" << endl;
    } else if (first < min && second < min) {
        cout << first << "-N " << second << "-N" << endl;
        cout << "zhang da zai lai ba" << endl;
    } else if(first < min && second >= max) {
        cout << first << "-Y " << second << "-Y" << endl;
        cout << "qing 2 zhao gu hao 1" << endl;
    } else if (second < min && first >= max) {
        cout << first << "-Y " << second << "-Y" << endl;
        cout << "qing 1 zhao gu hao 2" << endl;
    } else if(first >= min && first < max && second < min) {
        cout << first << "-Y " << second << "-N" << endl;
        cout << "1: huan ying ru guan" << endl;
    } else if(second >= min && second < max && first < min) {
        cout << first << "-N " << second << "-Y" << endl;
        cout << "2: huan ying ru guan" << endl;
    }
    return 0;
}