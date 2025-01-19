#include <stdio.h>

int main() {
    int N;
    double sum = 0.0, term;
    int sign = 1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        term = sign * (1.0 / (1 + 3 * i));
        sum += term;
        sign = -sign; 
    }

    printf("%.4lf\n", sum);

    return 0;
}