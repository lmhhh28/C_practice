#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    getchar();

    for (int i = 0; i < n; ++i) {
        int cnt = 0, flag = 1;
        int c;

        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) {
                break;
            }
            if (c == 'S') {
                ++cnt;
            } else if (c == 'X') {
                --cnt;
            }
            if (cnt > k || cnt < 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 0 && c != '\n' && c != EOF) {
            while ((c = getchar()) != '\n' && c != EOF) {
            }
        }

        if (cnt != 0) {
            flag = 0;
        }

        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
