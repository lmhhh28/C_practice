#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

struct AccuInt {
    int state;
    vector<int> vec;
    string buffer;
    AccuInt() : state(0) {}
    AccuInt(int len) { vec.resize(len, 0); }
    int Init() {
        if(buffer[0] == '-') { state = 1; }
        int begin = state, flag = 0;
        for(; begin < buffer.length(); ++begin)
        { if(buffer[begin]-'0') { flag = 1; break; } }
        if(!flag) { 
            vec.emplace_back(0); }
        else {
            for(int i = buffer.length()-1; i>=begin; --i) {
                if(state)
                { vec.emplace_back('0' - buffer[i]); }
                else { vec.emplace_back(buffer[i] - '0'); }
            }
        }
        return flag;
    }
    AccuInt& operator=(const AccuInt& a) {
        if(this != &a) {
            state = a.state;
            vec = a.vec;
            buffer = a.buffer;
        }
        return *this;
    }
    friend AccuInt Multi(AccuInt& a, AccuInt& b) {
        AccuInt res(a.vec.size()+b.vec.size());
        cout << res.vec.size() << endl;
        res.state = a.state^b.state;
        for(int i = 0; i < b.vec.size(); ++i) {
            for(int j = 0; j < a.vec.size(); ++j) {
                res.vec[i+j] += a.vec[j]*b.vec[i];
                res.vec[i+j+1] += res.vec[i+j] / 10;
                res.vec[i+j] %= 10;
            }
        }
        int cnt = res.vec.size() - 1;
        while(!res.vec[cnt]) {
            res.vec.pop_back();
            --cnt;
        }
        return res;
    }
    friend istream& operator>>(istream& is, AccuInt& num) {
        is >> num.buffer;
        num.Init();
        return is;
    }
    friend ostream& operator<<(ostream& os, const AccuInt& num) {
        if(num.state) { os << '-'; }
        for(int i = num.vec.size() - 1; i >= 0; --i) { 
            if(num.state)
            { os << -num.vec[i]; }
            else { os << num.vec[i]; } 
        }
        return os;
    }
};

void test() {
    AccuInt a, b, res;
    cin >> a >> b;
    res = Multi(a, b);
    cout << res.vec.size() << ' ' << a.vec.size() << ' ' << b.vec.size() << endl;
    // cout << a.buffer << endl;
    if(res.vec.size() >= 1000) {
        printf("错误：位数超限。\n");
    } else {
         cout << res << endl;   
    }
}

int main() {
    test();
    return 0;
}