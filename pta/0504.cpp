#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>::iterator binFind(vector<int>::iterator begin, 
vector<int>::iterator end, int num)
{
    vector<int>::iterator it = end, bottom = begin, top = end;
    while(1) {
        if(*bottom == num) {
            it = bottom;
            break;
        } 
        else if(top - bottom == 1) { break; } 
        else {
            vector<int>::iterator middle = bottom + (top - bottom) / 2;
            *middle > num ? top = middle : bottom = middle;
        }
    }
    return it;
}


int main() {
    int len, num; cin >> len;
    vector<int> arr;
    for(int i = 0; i < len; ++i) {
        cin >> num;
        arr.emplace_back(num);
    }
    while(1) {
        cin >> num;
        if(num == -1) { break; }
        // vector<int>::iterator it = binFind(arr.begin(), arr.end(), num);
        vector<int>::iterator it = find(arr.begin(), arr.end(), num);
        if(it != arr.end()) { cout << it - arr.begin() + 1 << " "; }
        else { cout << 0 << " "; }
    }
    cout << endl;
}