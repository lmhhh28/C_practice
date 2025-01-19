#include <stdio.h>

int main() {
    int n;
    int nums[1001];  // 存储数组
    int max_sum = 0; // 最大和
    int max_pos = 1; // 最大和的起始位置
    
    // 读取数组长度
    scanf("%d", &n);
    
    // 读取数组元素
    for(int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // 计算第一组和（作为初始最大值）
    max_sum = nums[1] + nums[2] + nums[3] + nums[4];
    
    // 遍历所有可能的起始位置
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        
        // 计算从位置i开始的4个数之和
        for(int j = 0; j < 4; j++) {
            int pos = i + j;
            // 如果位置超出数组范围，则回到开头
            if(pos > n) pos -= n;
            sum += nums[pos];
        }
        
        // 更新最大值
        if(sum > max_sum) {
            max_sum = sum;
            max_pos = i;
        }
    }
    
    // 输出结果
    printf("%d %d\n", max_sum, max_pos);
    
    return 0;
}