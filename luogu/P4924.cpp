#include<bits/stdc++.h>
using namespace std;

int c1[666][666], c2[666][666];

inline void rotateClockwise(int cx, int cy, int r) {
    int size = 2 * r + 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c2[i][j] = c1[cy + r - j][cx - r + i];
        }
    }
    for (int i = 0; i < size; i++) {
        memcpy(c1[cy - r + i] + cx - r, c2[i], sizeof(int) * size);
    }
}

inline void rotateCounterClockwise(int cx, int cy, int r) {
    for (int i = 0; i < 3; i++) {
        rotateClockwise(cx, cy, r);
    }
}

int main() {
    int n, times;
    cin >> n >> times;

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c1[i][j] = ++k;
        }
    }

    for (int i = 0; i < times; i++) {
        int x, y, r, a;
        cin >> x >> y >> r >> a;
        x--; y--;
        if (a == 1) {
            rotateCounterClockwise(y, x, r);
        } else {
            rotateClockwise(y, x, r);
        }
        memset(c2, 0, sizeof(c2));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
