#include <stdio.h>

int main() {
    int count[10];  // 存储0-9每个数字的个数
    
    // 读取每个数字的个数
    for(int i = 0; i < 10; i++) {
        scanf("%d", &count[i]);
    }
    
    // 找到第一个非零数字作为首位
    for(int i = 1; i < 10; i++) {
        if(count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    
    // 按顺序输出剩余的所有数字
    for(int i = 0; i < 10; i++) {
        while(count[i] > 0) {
            printf("%d", i);
            count[i]--;
        }
    }
    
    printf("\n");
    return 0;
}