#include <stdio.h>

int main() {
    int N, i, j, total_sum = 0;
    int digits[10];

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &digits[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i != j) {
                total_sum += digits[i] * 10 + digits[j];
            }
        }
    }

    printf("%d\n", total_sum);

    return 0;
}
