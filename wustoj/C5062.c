#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // 打印上半部分
    for (int i = 0; i < n / 2 + 1; i++) {
        // 打印前面的空格
        for (int j = 0; j < n / 2 - i; j++) {
            printf(" ");
        }
        // 打印*和空格
        printf("*");
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    // 打印下半部分
    for (int i = n / 2 - 1; i >= 0; i--) {
        // 打印前面的空格
        for (int j = 0; j < n / 2 - i; j++) {
            printf(" ");
        }
        // 打印*和空格
        printf("*");
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    return 0;
}