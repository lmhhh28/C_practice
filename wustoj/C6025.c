#include <stdio.h>

int main() {
    int n;
    int matrix[30][30];
    int new_matrix[30][30];
    int S1 = 0, S2 = 1;
    
    // 读取方阵大小
    scanf("%d", &n);
    
    // 读取方阵元素
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // 计算S1：对角线元素之和（注意中心元素只计算一次）
    for(int i = 0; i < n; i++) {
        S1 += matrix[i][i];                // 主对角线
        if(i != n-1-i) {                  // 如果不是中心元素
            S1 += matrix[i][n-1-i];       // 副对角线
        }
    }
    
    // 计算S2：对角线上行列下标均为偶数的元素乘积
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {                  // 行下标为偶数
            if(i % 2 == 0) {              // 主对角线上的元素（行=列）
                S2 *= matrix[i][i];
            }
            if((n-1-i) % 2 == 0) {        // 副对角线上的元素（列为偶数）
                if(i != n-1-i) {          // 避免重复计算中心元素
                    S2 *= matrix[i][n-1-i];
                }
            }
        }
    }
    
    // 顺时针旋转90度
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            new_matrix[j][n-1-i] = matrix[i][j];
        }
    }
    
    // 输出S1和S2
    printf("%d %d\n", S1, S2);
    
    // 输出旋转后的矩阵
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", new_matrix[i][j]);
            if(j < n-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}