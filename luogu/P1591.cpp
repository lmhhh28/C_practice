#include<bits/stdc++.h>
using namespace std;
string factorial(int n) {
    vector<int> res(1, 1);
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < res.size(); j++) {
            int prod = res[j] * i + carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    string result;
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        result += to_string(*it);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        string fact = factorial(n);
        cout << count(fact.begin(), fact.end(), '0' + a) << endl;
    }
    return 0;
}