#include <stdio.h>

int main() {
    unsigned long long N;
    int digit_count = 0, digit_sum = 0;

    scanf("%llu", &N);

    while (N > 0) {
        digit_sum += N % 10;   // 计算各位数字之和
        N /= 10;               // 移除最后一位
        digit_count++;         // 统计位数
    }

    printf("%d %d\n", digit_count, digit_sum);

    return 0;
}