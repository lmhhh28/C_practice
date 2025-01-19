#include <stdio.h>
#include <math.h>

// 判断是否为素数的函数
int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int M, N, count = 0, sum = 0;

    scanf("%d %d", &M, &N);

    for (int i = M; i <= N; i++) {
        if (is_prime(i)) {
            count++;        // 统计素数个数
            sum += i;       // 累加素数的和
        }
    }

    printf("%d %d\n", count, sum);

    return 0;
}