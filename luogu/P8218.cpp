#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    size_t lenth; cin >> lenth;
    vector<int> sum;
    int num, s = 0;
    sum.emplace_back(s);
    for(size_t i = 0; i < lenth; ++i) {
        cin >> num;
        s += num;
        sum.emplace_back(s);
    }
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        size_t begin, end;
        cin >> begin >> end;
        cout << sum[end] - sum[begin - 1] << endl;
    }
    return 0;
}