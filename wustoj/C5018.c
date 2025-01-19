#include <stdio.h>

void print_sand_clock(int N) {
    int k = 0; // 沙漏的上半部分的层数
    int total_stars = 1; // 沙漏使用的总符号数，初始值为1，即中心1个符号
    int used_stars = 1;  // 用于计算已使用的符号数量
    
    // 找到最大的k，使得(2 * k - 1) + (2 * (k - 1) - 1) + ... + 1 <= N
    while (total_stars <= N) {
        k++;
        total_stars = 2 * k * k - 1; // 根据公式计算符号总数 (1 + 3 + 5 + ... + (2k-1)) * 2 - 1
        if (total_stars > N) {
            k--; // 超出N时，恢复到前一个合法的k
            total_stars = 2 * k * k - 1; // 恢复合法符号总数
            break;
        }
    }
    
    used_stars = total_stars; // 用于打印后计算剩余的符号
    
    // 打印上半部分和中间部分
    for (int i = k; i > 0; i--) {
        for (int j = 0; j < k - i; j++) {
            printf(" "); // 打印空格
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*"); // 打印符号
        }
        printf("\n");
    }
    
    // 打印下半部分
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < k - i; j++) {
            printf(" "); // 打印空格
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*"); // 打印符号
        }
        printf("\n");
    }
    
    // 输出剩余的符号数
    printf("%d\n", N - used_stars);
}

int main() {
    int N;
    scanf("%d", &N);  // 输入符号数
    print_sand_clock(N);
    return 0;
}
