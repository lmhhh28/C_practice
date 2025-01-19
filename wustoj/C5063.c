#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int a;
    scanf("%d", &a);

    for (int i = a; ; i++) {
        if (is_prime(i) && is_prime(i + 2)) {
            printf("%d %d\n", i, i + 2);
            break;
        }
    }

    return 0;
}
