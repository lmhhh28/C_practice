#include <stdio.h>

int main() {
    int n, m;
    int matrix[10][10];
    
    // 读取矩阵的行数和列数
    scanf("%d %d", &n, &m);
    
    // 读取矩阵元素
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // 打印原始矩阵
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if(j < m-1) printf(" ");
        }
        printf("\n");
    }
    
    // 打印转置矩阵
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            printf("%d", matrix[i][j]);
            if(i < n-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
