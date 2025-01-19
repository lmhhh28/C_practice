#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // 先检查输入是否有解的基本条件：脚数必须为偶数，且总脚数 >= 2*总头数
    if (n % 2 != 0 || n < 2 * m || n > 4 * m) {
        printf("Error\n");
        return 0;
    }

    // 检查 (n - 2*m) 是否为偶数以保证 y 是整数
    if ((n - 2 * m) % 2 != 0) {
        printf("Error\n");
        return 0;
    }

    // 通过代数法解出兔子和鸡的数量
    int y = (n - 2 * m) / 2;  // 兔的数量
    int x = m - y;  // 鸡的数量

    // 输出鸡和兔的数量
    if (x >= 0 && y >= 0) {
        printf("%d %d\n", x, y);
    } else {
        printf("Error\n");
    }

    return 0;
}
