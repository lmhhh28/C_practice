#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    while (n != 1) {
        if (n % 2 == 0) {
            printf("%lld/2=%lld\n", n, n / 2);
            n = n / 2;
        } else {
            printf("%lld*3+1=%lld\n", n, n * 3 + 1);
            n = n * 3 + 1;
        }
    }
    return 0;
}
