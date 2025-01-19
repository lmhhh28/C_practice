#include <stdio.h>

void print_diamond(int n) {
    // 上半部分（包含中间行）
    for (int i = 1; i <= n; i++) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        // 换行
        printf("\n");
    }
    
    // 下半部分（不包含中间行）
    for (int i = n - 1; i >= 1; i--) {
        // 打印空格
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        // 换行
        printf("\n");
    }
}

int main() {
    int n;
    // 输入n
    scanf("%d", &n);
    
    // 调用函数打印菱形
    print_diamond(n);
    
    return 0;
}
