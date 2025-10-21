#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int m, n, k;
    int seq[MAX];
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &seq[j]);
        }
        int stack[MAX], top = -1;
        int current = 1;
        int valid = 1;
        for (int j = 0; j < n; j++) {
            int x = seq[j];
            while (top == -1 || stack[top] != x) {
                if (current > n) {
                    valid = 0;
                    break;
                }
                stack[++top] = current++;
                if (top >= m) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) break;
            top--;
        }
        printf(valid ? "YES\n" : "NO\n");
    }
    return 0;
}
