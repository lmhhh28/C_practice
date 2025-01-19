#include <stdio.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int n, int primes[], int *prime_count) {
    bool is_prime[n + 1];
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    *prime_count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[(*prime_count)++] = i;
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int primes[n], prime_count;
    sieve_of_eratosthenes(n, primes, &prime_count);

    int start_index = prime_count >= k ? prime_count - k : 0;
    int total_sum = 0;

    for (int i = prime_count - 1; i >= start_index; i--) {
        total_sum += primes[i];
        printf("%d", primes[i]);
        if (i > start_index) {
            printf("+");
        }
    }
    printf("=%d\n", total_sum);

    return 0;
}
