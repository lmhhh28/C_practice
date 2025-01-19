#include <stdio.h>

int main() {
    int n;
    int matrix[100][100];
    int num = 1;        // 要填入的数字
    int col = 0;        // 当前列
    int row = 0;        // 当前行
    int direction = 1;  // 方向：1表示向下，-1表示向上
    
    scanf("%d", &n);
    
    // 从右向左填充
    for(col = n-1; col >= 0; col--) {
        if(direction == 1) {  // 向下填充
            for(row = n-1; row >= 0; row--) {
                matrix[row][col] = num++;
            }
        } else {  // 向上填充
            for(row = 0; row < n; row++) {
                matrix[row][col] = num++;
            }
        }
        direction = -direction;  // 改变方向
    }
    
    // 输出方阵
    for(row = 0; row < n; row++) {
        for(col = 0; col < n; col++) {
            printf("%5d", matrix[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}