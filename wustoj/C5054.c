#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int excellent_count = 0;
    int pass_count = 0;
    int fail_count = 0;

    int score;

    for (int i = 0; i < N; i++) {
        scanf("%d", &score);
        if (score >= 85) {
            excellent_count++;
        } else if (score >= 60) {
            pass_count++;
        } else {
            fail_count++;
        }
    }

    printf("%d %d %d\n", excellent_count, pass_count, fail_count);

    return 0;
}