#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    size_t  n;
    int     q;
    cin >> n >> q;
    vector<vector<int>> bag(n);
    vector<int> max(n);
    for(int i = 0; i < q; ++i) {
        int method, j, k, val;
        cin >> method;
        if (method == 1) {
            cin >> j >> k >> val;
            if (k > max[j - 1]) {
                bag[j - 1].resize(k);
                max[j - 1] = k;
            }
            bag[j - 1][k - 1] = val;
        } else if (method == 2) {
            cin >> j >> k;
            cout << bag[j - 1][k - 1] << endl;
        }
    }
    return 0;
}