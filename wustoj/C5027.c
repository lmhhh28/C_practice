#include <stdio.h>

int main() {
    int m, n;
    double sum = 0.0;

    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        sum += i * i + 1.0 / i;
    }

    printf("%.6lf\n", sum);

    return 0;
}
