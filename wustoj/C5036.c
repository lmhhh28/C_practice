#include <stdio.h>

int min_months_to_reach_n_rabbits(int N) {
    if (N == 1) {
        return 1;
    }

    int a = 1, b = 1;
    int month = 2;

    while (b < N) {
        int temp = b;
        b = a + b;
        a = temp;
        month++;
    }

    return month;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", min_months_to_reach_n_rabbits(N));

    return 0;
}
