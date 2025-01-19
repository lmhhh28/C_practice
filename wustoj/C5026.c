#include <stdio.h>

double factorial(int x) {
    double result = 1.0;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    double combination = factorial(n) / (factorial(m) * factorial(n - m));

    printf("%.0lf\n", combination);

    return 0;
}