#include <iostream>
using namespace std;

int main() {
    int out, state, in;
    cin >> out >> state >> in;
    if(out > 35 && in >= 33) {
        if(state){
            cout << "Bu Tie" << endl;
        } else {
            cout << "Shi Nei" << endl;
        }
        cout << out << endl;
    } else {
        if(state) {
            cout << "Bu Re" << endl;
        } else {
            cout << "Shu Shi" << endl;
        }
        cout << in << endl;
    }
    return 0;
}