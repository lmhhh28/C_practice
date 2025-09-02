#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s.length() == 4) {
        int num = (s[0] - 48) * 10 + (s[1] - 48);
        if(num < 22) {
            s = "20" + s; 
        } else {
            s = "19" + s;
        }
    }
    s.insert(4, "-");
    cout << s << endl;
    return 0;
}