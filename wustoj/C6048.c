#include <stdio.h>

int main() {
    int N;
    int seq[101];    // 存储第一行序列
    int pos[101];    // 存储每个数在序列中的位置
    int matrix[101][101];  // 存储拉丁方阵
    
    // 读取N
    scanf("%d", &N);
    
    // 读取第一行序列
    for(int i = 1; i <= N; i++) {
        scanf("%d", &seq[i]);
        pos[seq[i]] = i;  // 记录每个数在序列中的位置
    }
    
    // 生成拉丁方阵
    for(int num = 1; num <= N; num++) {  // 对每个数字
        int curr_pos = pos[num];  // 该数字在序列中的初始位置
        
        // 填充该数字在每一行的位置
        for(int row = 1; row <= N; row++) {
            matrix[row][curr_pos] = num;
            curr_pos = seq[curr_pos];  // 移动到序列指示的下一个位置
        }
    }
    
    // 输出拉丁方阵
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            printf("%d", matrix[i][j]);
            if(j < N) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}