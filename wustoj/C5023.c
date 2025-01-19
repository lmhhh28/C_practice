#include <stdio.h>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int N, sum = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        sum += factorial(i);
    }

    printf("%d\n", sum);

    return 0;
}