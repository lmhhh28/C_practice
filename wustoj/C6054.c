#include <stdio.h>
#include <string.h>

#define MAX_LEN 100005

// 将当前项加到结果中
void add_to_sum(char *sum, char *curr, int *sum_len) {
    int carry = 0;
    int i = *sum_len - 1;
    int j = strlen(curr) - 1;
    
    // 从右向左逐位相加
    while(i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? sum[i] - '0' : 0;
        int digit2 = (j >= 0) ? curr[j] - '0' : 0;
        int total = digit1 + digit2 + carry;
        
        // 如果需要扩展sum的长度
        if(i < 0) {
            // 将所有数字向右移动一位
            for(int k = *sum_len; k > 0; k--) {
                sum[k] = sum[k-1];
            }
            (*sum_len)++;
            i = 0;
        }
        
        sum[i] = (total % 10) + '0';
        carry = total / 10;
        
        i--;
        j--;
    }
}

int main() {
    int A, N;
    scanf("%d %d", &A, &N);
    
    if(N == 0) {
        printf("0\n");
        return 0;
    }
    
    char sum[MAX_LEN] = "0";  // 存储最终结果
    int sum_len = 1;          // 结果的长度
    char curr[MAX_LEN];       // 存储当前项
    int curr_len = 0;         // 当前项的长度
    
    // 生成每一项并累加
    for(int i = 1; i <= N; i++) {
        // 生成当前项
        curr_len = 0;
        for(int j = 0; j < i; j++) {
            curr[curr_len++] = A + '0';
        }
        curr[curr_len] = '\0';
        
        // 将当前项加到sum中
        add_to_sum(sum, curr, &sum_len);
    }
    
    // 输出结果
    for(int i = 0; i < sum_len; i++) {
        printf("%c", sum[i]);
    }
    printf("\n");
    
    return 0;
}