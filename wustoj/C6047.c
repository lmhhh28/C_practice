#include <stdio.h>

int main() {
    int N;
    char board[12][12];  // 最大2N=10，留出余量
    int wrong_count = 0; // 错误次数
    int remain = 0;      // 剩余未匹配的符号数
    
    // 读取游戏盘面大小
    scanf("%d", &N);
    
    // 读取游戏盘面
    for(int i = 1; i <= 2*N; i++) {
        for(int j = 1; j <= 2*N; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] != '*') {
                remain++;
            }
        }
    }
    
    // 读取操作次数
    int K;
    scanf("%d", &K);
    
    // 处理每次操作
    for(int k = 0; k < K; k++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        // 检查坐标是否越界或选择了已消除的位置
        if(x1 < 1 || x1 > 2*N || y1 < 1 || y1 > 2*N ||
           x2 < 1 || x2 > 2*N || y2 < 1 || y2 > 2*N ||
           board[x1][y1] == '*' || board[x2][y2] == '*') {
            printf("Uh-oh\n");
            wrong_count++;
            if(wrong_count >= 3) {
                printf("Game Over\n");
                return 0;
            }
            continue;
        }
        
        // 检查是否匹配
        if(board[x1][y1] == board[x2][y2]) {
            // 匹配成功
            board[x1][y1] = board[x2][y2] = '*';
            remain -= 2;
            
            // 输出当前盘面
            for(int i = 1; i <= 2*N; i++) {
                for(int j = 1; j <= 2*N; j++) {
                    printf("%c", board[i][j]);
                    if(j < 2*N) printf(" ");
                }
                printf("\n");
            }
            
            // 检查是否全部匹配完成
            if(remain == 0) {
                printf("Congratulations!\n");
                return 0;
            }
        } else {
            printf("Uh-oh\n");
            wrong_count++;
            if(wrong_count >= 3) {
                printf("Game Over\n");
                return 0;
            }
        }
    }
    
    return 0;
}