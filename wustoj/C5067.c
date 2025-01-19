#include <stdio.h>

int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != 1 && i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int are_amicable(int a, int b) {
    return sum_of_divisors(a) == b && sum_of_divisors(b) == a;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (are_amicable(a, b)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
