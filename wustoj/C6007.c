#include <stdio.h>

int main() {
    int m, n;
    int arr[30][30];
    int min_i = 0, min_j = 0;
    
    // 读取矩阵大小
    scanf("%d %d", &m, &n);
    
    // 读取矩阵元素并找出最小值的位置
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] < arr[min_i][min_j]) {
                min_i = i;
                min_j = j;
            }
        }
    }
    
    // 打印处理前的矩阵
    printf("before:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    
    // 交换最小元素所在行与最后一行
    if(min_i != m-1) {  // 如果最小元素不在最后一行
        for(int j = 0; j < n; j++) {
            int temp = arr[min_i][j];
            arr[min_i][j] = arr[m-1][j];
            arr[m-1][j] = temp;
        }
    }
    
    // 打印处理后的矩阵
    printf("after:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
