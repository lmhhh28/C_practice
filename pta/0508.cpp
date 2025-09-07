#include <iostream>
#include <vector>
#include <exception>
using namespace std;

struct Int {
    vector<int> num;
    string ibuffer;
    bool state;
    int arr[4] = {1, 10, 100, 1000, };
    Int() : state(0) {}
    Int(int);
    Int(const string&);
    Int(const Int& obj) { *this = obj; }
    Int(const Int&& obj) noexcept { *this = obj; }
    void trans();
    void detect(const char);
    friend Int&& add(const Int&, const Int&, Int&); 
    friend Int&& sub(Int&, Int&, Int&);
    friend int comp(const Int&, const Int&);
    Int& operator=(const Int&);
    Int& operator=(const Int&&);
    friend bool operator==(Int&, Int&);
    friend bool operator<(Int&, Int&);
    friend bool operator<=(Int&, Int&);
    friend bool operator>(Int&, Int&);
    friend bool operator>=(Int&, Int&);
    friend istream& operator>>(istream&, Int&);
    friend ostream& operator<<(ostream&, const Int&);
    friend Int operator+(Int&, Int&);
    friend Int operator-(Int&, Int&);
};

void test() {
    Int a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
}

void test_1() {
    Int a, b;
    cin >> a >> b;
    // cout << (a > b) << endl;
    cout << a + b << endl;
}

Int& Int::operator=(const Int& obj) {
    if(this != &obj) {
        state = obj.state;
        num = obj.num;
        ibuffer = obj.ibuffer;
    }
    return *this;
}

Int& Int::operator=(const Int&& obj) {
    if(this != &obj) {
        state = obj.state;
        num = obj.num;
        ibuffer = obj.ibuffer;
    }
    return *this;
}

inline Int&& add(const Int& a, const Int& b, Int& res) {
    if(a.num.empty()) { throw runtime_error("The Left is Null!"); }
    if(b.num.empty()) { throw runtime_error("The Right is Null!"); }
    size_t a_size = a.num.size(), b_size = b.num.size();
    if((a_size < b_size) || a.state || b.state)
    { throw runtime_error("This Method is Excusive!"); } 
    for(size_t i = 0; i < a_size; ++i) {
        if(i < b_size) { res.num.emplace_back(a.num[i] + b.num[i]); }
        else { res.num.emplace_back(a.num[i]); }   
    }
    for(size_t i = 0; i < res.num.size() - 1; ++i) {
        res.num[i + 1] += res.num[i] / 10000;
        res.num[i] %= 10000;
    }
    int temp = *res.num.rbegin() / 10000;
    if(temp) {
        *res.num.rbegin() %= 10000;
        res.num.emplace_back(temp);
    }
    return move(res);
}

inline Int&& sub(Int& a, Int& b, Int& res) {
    if(a.num.empty()) { throw runtime_error("The Left is Null!"); }
    if(b.num.empty()) { throw runtime_error("The Right is Null!"); }
    if((a < b) || a.state || b.state)
    { throw runtime_error("This Method is Excusive!"); }
    size_t a_size = a.num.size(), b_size = b.num.size();
    for(size_t i = 0; i < a_size; ++i) {
        if(i < b_size) { res.num.emplace_back(a.num[i] - b.num[i]); }
        else { res.num.emplace_back(a.num[i]); }
    }
    for(size_t i = 0; i < res.num.size() - 1; ++i) {
        if(res.num[i] < 0) { res.num[i] += 10000; --res.num[i + 1]; }
    }
    while(res.num.size() > 1) {
        vector<int>::reverse_iterator it = res.num.rbegin();
        if(!*it) { res.num.pop_back(); }
        else { break; }
    }
    return move(res);
}


Int operator+(Int& a, Int& b) {
    if(a.num.empty()) { throw runtime_error("The Left is Null!"); }
    if(b.num.empty()) { throw runtime_error("The Right is Null!"); }
    size_t a_size = a.num.size(), b_size = b.num.size();
    Int res;
    if(!a.state) {
        if(!b.state) {
            if(a_size >= b_size) { res = add(a, b, res); }
            else { res = add(b, a, res); } 
        } else {
            b.state = 0;
            if(a >= b) { res = sub(a, b, res); }
            else { res = sub(b, a, res); res.state = 1; }
            b.state = 1;
        }
    } else {
        if(!b.state) {
            a.state = 0;
            if(b >= a) { res = sub(b, a, res); }
            else { res = sub(a, b, res); res.state = 1; }
            a.state = 1; 
        } else {
            a.state = 0; b.state = 0;
            if(a_size > b_size) { res = add(a, b, res); res.state = 1; }
            else { res = add(b, a, res); res.state = 1; }
            a.state = 1; b.state = 1;
        }
    }
    return res;
}

Int operator-(Int& a, Int& b) {
    b.state = !b.state;
    Int res = a + b;
    b.state = !b.state;
    return res;
}

int comp(const Int& a, const Int& b) {
    if(a.state || b.state) { throw runtime_error("This Method is Excusive!"); }
    int flag = 0;
    if(a.num.size() > b.num.size()) { flag = 1; }
    else if(a.num.size() < b.num.size()) { flag = -1; }
    else {
        size_t size = a.num.size();
        for(size_t i = 0; i < size; ++i) {
            if(a.num[size - i - 1] > b.num[size - i - 1]) { flag = 1; break; }
            else if(a.num[size - i - 1] < b.num[size - i - 1]) { flag = -1; break; }
        }
    }
    return flag;
}

bool operator>(Int& a, Int& b) {
    bool flag = true;
    if(a == b) { flag = false; }
    else {
        if((!a.state && !b.state && !(comp(a, b) + 1)) 
        || (a.state && !b.state)) { flag = false; }
        if(a.state && b.state) {
            a.state = 0; b.state = 0;
            if(!(comp(a, b) - 1)) { flag = false; }
            a.state = 1; b.state = 1;
        }
    }
    return flag;
}

bool operator<(Int& a, Int& b) { return !(a == b) && !(a > b); }
bool operator<=(Int& a, Int& b) { return (a == b) || (a < b); }
bool operator>=(Int& a, Int& b) { return (a == b) || (a > b); }

bool operator==(Int& a, Int& b) {
    bool ret = false;
    if(a.state && b.state) { a.state = 0; b.state = 0; ret = true; }
    bool flag = !(a.state - b.state) && !comp(a, b) ? true : false;
    if(ret) {a.state = 1; b.state = 1; }
    return flag;
}

inline void Int::detect(const char ch) {
    if(ch < '0' || ch > '9') { throw runtime_error("Invalid Input"); }
}

inline void Int::trans() {
    if(ibuffer.empty()) { throw runtime_error("None Input!"); }
    size_t cnt = 0;
    if(ibuffer[cnt] == '-') { state = 1; ++cnt; }
    for(; ibuffer[cnt] == '0' && cnt < ibuffer.size(); ++cnt)
    { detect(ibuffer[cnt]); }
    size_t len = ibuffer.length() - cnt;
    if(!(state && ibuffer.length() == 1) && !len)
    { num.emplace_back(0); state = 0; }
    for(size_t i = 0, sum = 0; i < len; ++i) {
        char temp = ibuffer[ibuffer.length() - 1 - i];
        detect(temp);
        if(!(i % 4) && i) { num.emplace_back(sum); sum = 0; }
        sum += (temp - '0') * arr[i % 4];
        if(i == len - 1) { num.emplace_back(sum); }
    }
    ibuffer.clear();
}          
istream& operator>>(istream& is, Int& number) {
    is >> number.ibuffer;
    number.trans();
    return is;
}

ostream& operator<<(ostream& os, const Int& number) {
    if(number.num.empty()) { throw runtime_error("None Value!"); }
    if(number.state && *number.num.rbegin()) { os << '-'; }
    for(auto it = number.num.rbegin(); it != number.num.rend(); ++it) {
        if(it != number.num.rbegin()) {
            int dig = 0, temp = *it;
            if(!temp) { dig = 1; }
            while(temp) { temp /= 10; ++dig; }
            for(; dig < 4; ++dig) { os << '0'; }
        }
        os << *it;
    }
    return os;
}

int main() {
    // test();
    test_1();
    return 0;
}

