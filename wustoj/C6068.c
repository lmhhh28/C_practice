#include <stdio.h>

int main() {
    int n;
    int votes[9] = {0};  // 存储1-8号栏目的投票数，下标0不使用
    int vote;
    
    // 读取观众人数
    scanf("%d", &n);
    
    // 读取每个观众的投票
    for(int i = 0; i < n; i++) {
        scanf("%d", &vote);
        // 只统计有效投票（1-8）
        if(vote >= 1 && vote <= 8) {
            votes[vote]++;
        }
    }
    
    // 按顺序输出每个栏目的得票数
    for(int i = 1; i <= 8; i++) {
        printf("%d %d\n", i, votes[i]);
    }
    
    return 0;
}