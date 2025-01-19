#include <stdio.h>

int main() {
    int n, k;
    int lights[1001] = {0};  // 0表示关闭，1表示打开
    
    // 读取灯的数量和人数
    scanf("%d %d", &n, &k);
    
    // 第一个人把所有灯打开
    for(int i = 1; i <= n; i++) {
        lights[i] = 1;
    }
    
    // 从第2个人到第k个人
    for(int person = 2; person <= k; person++) {
        // 处理该人能够触及的所有灯
        for(int light = person; light <= n; light += person) {
            lights[light] = !lights[light];  // 切换灯的状态
        }
    }
    
    // 输出所有开着的灯
    int first = 1;  // 用于控制空格输出
    for(int i = 1; i <= n; i++) {
        if(lights[i]) {
            if(!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    
    return 0;
}