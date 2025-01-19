#include<bits/stdc++.h>
using namespace std;

int n, na, nb, sa, sb, fa[201], fb[201];

inline void pk(int a, int b, int &s1, int &s2) {
    if (a == b) return;
    if (a > b) {
        pk(b, a, s2, s1);
        return;
    }
    switch (a) {
        case 0: ++(b == 2 || b == 3 ? s1 : s2); return;
        case 1: ++(b == 3 ? s1 : s2); return;
        case 2: ++(b == 4 ? s1 : s2); return;
        case 3: ++s1; return;
    }
}

int main() {
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; ++i) scanf("%d", fa + i);
    for (int i = 0; i < nb; ++i) scanf("%d", fb + i);
    for (int i = 0; i < n; ++i) pk(fa[i % na], fb[i % nb], sa, sb);
    printf("%d %d", sa, sb);
    return 0;
}
