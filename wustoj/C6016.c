#include <stdio.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int N) {
    bool is_prime[N + 1];
    for (int i = 0; i <= N; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int first = 1;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    sieve_of_eratosthenes(N);
    return 0;
}
