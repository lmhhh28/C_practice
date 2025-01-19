#include <stdio.h>

int main() {
    int n, x;
    int a[101];  // 多留一个位置用于插入
    
    // 读取数组长度
    scanf("%d", &n);
    
    // 读取有序数组
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // 读取待插入的数
    scanf("%d", &x);
    
    // 找到插入位置并移动元素
    int i;
    for(i = n - 1; i >= 0 && a[i] > x; i--) {
        a[i + 1] = a[i];
    }
    a[i + 1] = x;
    
    // 输出结果
    for(i = 0; i <= n; i++) {
        printf("%d", a[i]);
        if(i < n) printf(" ");  // 除了最后一个数，其他数后面都要加空格
    }
    printf("\n");
    
    return 0;
}