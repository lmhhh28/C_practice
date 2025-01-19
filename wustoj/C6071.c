#include <stdio.h>

// 检查数组是否有序且无重复
int checkArray(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] >= arr[i+1]) {
            return 0;  // 不是严格递增
        }
    }
    return 1;
}

int main() {
    int n, x;
    int arr[1000];
    
    // 读取n和x
    scanf("%d %d", &n, &x);
    
    // 读取数组
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 检查数组是否有序且无重复
    if(!checkArray(arr, n)) {
        printf("Invalid Value\n");
        return 0;
    }
    
    // 二分查找
    int left = 0, right = n-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        
        // 输出当前查找区间
        printf("[%d,%d][%d]\n", left, right, mid);
        
        if(arr[mid] == x) {
            printf("%d\n", mid);
            return 0;
        }
        else if(arr[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    printf("Not Found\n");
    return 0;
}