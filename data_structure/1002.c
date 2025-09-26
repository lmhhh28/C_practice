#include <stdio.h>
int main() {
    int n, m, max = 0; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        int num; scanf("%d", &num);
        if(m * num > max) {
            max = m * num;
        }
    }
    printf("%d\n", max);
    return 0;
}