#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len; cin >> len;
    vector<int> vec;
    for(int i = 0; i < len; ++i) {
        int num; cin >> num;
        vec.emplace_back(num);
    }
    
}
