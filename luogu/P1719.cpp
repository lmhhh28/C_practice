#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    size_t size; cin >> size;
    vector<vector<int>> vec(size + 1);
    for(size_t i = 0; i <= size; ++i) {
        int sum = 0;
        for(size_t j = 0; j <= size; ++j) {
            if(!i || !j) {
                vec[i].emplace_back(0);
            } else {
                int num; cin >> num;
                sum += num;
                vec[i].emplace_back(sum + vec[i - 1][j]);
            }
        }
    }
    int max = 0;
    for(size_t y_1 = 1; y_1 <= size; ++y_1) {
        for(size_t x_1 = 1; x_1 <= size; ++x_1 ) {
            for(size_t y_2 = 1; y_2 <= y_1; ++y_2) {
                for(size_t x_2 = 1; x_2 <= x_1; ++x_2) {
                    int cnt = 
                    vec[y_1][x_1]-vec[y_1][x_2-1]-vec[y_2-1][x_1]+vec[y_2-1][x_2-1];
                    if(cnt > max) {
                        max = cnt;
                    }
                }
            }
        }
    }
    cout << max << endl;
}