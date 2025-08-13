#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    size_t m, n;
    cin >> m >> n;
    vector<int> stu(m);
    for(size_t i = 0; i < m; ++i) {
        cin >> stu[i];
    }
    for(int i = 0; i < n; ++i) {
        int query;
        cin >> query;
        cout << stu[query - 1] << endl;
    }
    return 0;
}