#include <stdio.h>

int main() {
    int L, M;
    int trees[10001] = {0};  // 0表示树存在，1表示树被移走
    
    // 读取马路长度和区域数量
    scanf("%d %d", &L, &M);
    
    // 处理每个区域
    for(int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        
        // 标记这个区域内的树为移走状态
        for(int j = start; j <= end; j++) {
            trees[j] = 1;
        }
    }
    
    // 统计剩余的树
    int count = 0;
    for(int i = 0; i <= L; i++) {
        if(trees[i] == 0) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}