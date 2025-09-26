#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    size_t len; cin >> len;
    vector<int> dp;
    dp.emplace_back(0);
    for(size_t i = 1; i <= len; ++i) {
        int num; cin >> num;
        if(dp[i-1]+num > num) {
            dp.emplace_back(dp[i-1]+num);
        } else {
            dp.emplace_back(num);
        }
    }
    int max = 0x80000000;
    for(size_t i = 0; i <= len; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    for(size_t i = 1; i <= len; ++i) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    cout << max << endl;
}