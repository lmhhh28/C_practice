#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class String{
private:
    int length;
    vector<int> p_s, p_t;

public:
    String(int len) : length(len), p_s(len), p_t(len) {}

    void Inp_str(){
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < length; i++){
            p_s[i] = s[i] - '0';
            p_t[i] = t[i] - '0';
        }
    }
    bool Com_str(){
        for (int i = 0; i < length; i++){
            if (p_s[i] == 0 && p_t[i] == 1)
                return false;
            else if (p_s[i] == 1)
                return true;
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, length;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> length;
        String str(length);
        str.Inp_str();
        cout << (str.Com_str() ? "YES" : "NO") << endl;
    }
}
