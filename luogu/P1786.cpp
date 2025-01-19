#include<iostream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

string zwm[8] = {"", "BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};

struct Node {
    string name;
    string zw;
    int bg, lv, tk;
} ex[120];

int n;

bool cmpByBg(Node a, Node b) {
    return (a.bg == b.bg) ? a.tk < b.tk : a.bg > b.bg;
}

bool cmpByLv(Node a, Node b) {
    return (a.lv == b.lv) ? a.tk < b.tk : a.lv > b.lv;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ex[i].name >> ex[i].zw >> ex[i].bg >> ex[i].lv;
        ex[i].tk = i;
    }

    int rec = 1;
    while (rec <= n && (ex[rec].zw == zwm[1] || ex[rec].zw == zwm[2])) {
        rec++;
    }

    int tmp = rec;
    sort(ex + rec, ex + n + 1, cmpByBg);
    sort(ex + rec, ex + min(rec + 2, n + 1), cmpByLv);
    rec = min(rec + 2, n + 1);
    sort(ex + rec, ex + min(rec + 4, n + 1), cmpByLv);
    rec = min(rec + 4, n + 1);
    sort(ex + rec, ex + min(rec + 7, n + 1), cmpByLv);
    rec = min(rec + 7, n + 1);
    sort(ex + rec, ex + min(rec + 25, n + 1), cmpByLv);
    rec = min(rec + 25, n + 1);
    sort(ex + rec, ex + n + 1, cmpByLv);

    for (int i = tmp; i <= n; i++) {
        ex[i].zw = zwm[7];
        if (i < tmp + 38) ex[i].zw = zwm[6];
        if (i < tmp + 13) ex[i].zw = zwm[5];
        if (i < tmp + 6) ex[i].zw = zwm[4];
        if (i < tmp + 2) ex[i].zw = zwm[3];
    }

    for (int i = 1; i <= n; i++) {
        cout << ex[i].name << " " << ex[i].zw << " " << ex[i].lv << endl;
    }

    return 0;
}
