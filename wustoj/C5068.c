#include <stdio.h>

int digit_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;
    int found = 0;

    for (int i = 1; i <= N; i++) {
        if (digit_sum(i) == 15) {
            if (found && count % 8 == 0) {
                printf("\n");
            }
            printf("%6d", i);
            found = 1;
            count++;
        }
    }

    if (!found) {
        printf("None\n");
    } else {
        printf("\n");
    }

    return 0;
}
