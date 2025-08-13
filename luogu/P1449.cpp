#include <iostream>
#include <vector>
#include <string>

#define IsOp(ch) ch == '+' || ch == '-' || ch == '*' || ch == '/'
#define IsNum(ch) ch >= '0' && ch <= '9'
#define IsDot(ch) ch == '.'
#define IsEnd(ch) ch == '@'

using namespace std;

vector<char>& rec(vector<char>& rep);
int int_pow(int base, unsigned exp);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<char>    rep;
    vector<int>     rep_int;  
    char ch;
    while(cin >> ch) {
        rep.push_back(ch);
        if (IsEnd(ch))  break;
    } 
    for(vector<char>::iterator it = rep.begin(); it != rep.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    vector<char>::iterator it = rep.begin();
    while(!IsEnd(*it)) {
        int num = 0, dig = 0;
        while(IsNum(*it)) {
            ++dig;
            ++it;
        }
        vector<char>::iterator it_temp = it - 1;
        for(int i = 0; i < dig; ++i) {
            num += int_pow(10, i) * (*it_temp - 48);
            --it_temp;
        }
        rep_int.push_back(num);

    }
    // vector<char>::iterator it = rep.begin() + 1;
    // it = rep.erase(it - 1, it + 1);
    // for(vector<char>::iterator it = rep.begin(); it != rep.end(); ++it) {
    //     cout << *it;
    // }
    // cout << endl;
}

vector<char>& rec(vector<char>& rep) {
    if (rep[2] == '@') {
        return rep;
    } else {
        for(vector<char>::iterator it = rep.begin(); it != rep.end(); ++it) {
            int __num_1 = 0, __num_2 = 0, __re = 0;
            char op;
            if (IsOp(*it)) {
                op = *it;
                int i = 0;
                for(it = it - 2; IsNum(*it); --it) {
                    int exp = int_pow(10, i);
                    __num_1 += (*it - 48) * exp;
                }
                // cout << __num_1 << ' ' << __num_2 << endl;
                switch (op) {
                case '+':
                    __re = __num_1 + __num_2;
                    break;
                case '-':
                    __re = __num_1 - __num_2;
                    break;
                case '*':
                    __re = __num_1 * __num_2;
                    break;
                case '/':
                    __re = __num_1 / __num_2;
                    break;
                default:
                    break;
                }
                *(it - 4) = (char)(__re + 48);
                it = rep.erase(it - 2, it + 1);
                for(vector<char>::iterator it = rep.begin(); it != rep.end(); ++it) {
                    cout << *it;
                }
                cout << endl;
                break;
            }
        }
        return rec(rep);
    }
}

int int_pow(int base, unsigned exp) {
    int result = 1;
    while (exp) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}