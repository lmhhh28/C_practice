#include <stdio.h>

double factorial(int x) {
    double result = 1.0;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    double sum = 1.0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / factorial(i);
    }

    printf("%.8lf\n", sum);

    return 0;
}