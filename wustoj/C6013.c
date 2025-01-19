#include <stdio.h>

int main() {
    int n;
    int matrix[100][100] = {0};
    
    scanf("%d", &n);
    
    // 初始位置：第一行中间
    int row = 0;
    int col = n / 2;
    
    // 填充数字1到n*n
    for(int num = 1; num <= n * n; num++) {
        matrix[row][col] = num;
        
        // 保存当前位置
        int next_row = row;
        int next_col = col;
        
        // 计算下一个位置（右上方）
        next_row = (row - 1 + n) % n;
        next_col = (col + 1) % n;
        
        // 如果下一个位置已经有数字，就放在当前位置的下方
        if(matrix[next_row][next_col] != 0) {
            next_row = (row + 1) % n;
            next_col = col;
        }
        
        // 更新位置
        row = next_row;
        col = next_col;
    }
    
    // 输出幻方
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}