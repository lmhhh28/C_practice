#include <stdio.h>

int main() {
    int n, m, s;
    int people[100] = {0};  // 用0表示在圈内，1表示已出圈
    int count = 0;          // 已出圈的人数
    
    // 读取输入
    scanf("%d %d %d", &n, &m, &s);
    
    int current = s - 1;    // 当前报数的人（转换为0-based索引）
    
    // 直到所有人都出圈
    while(count < n) {
        int num = 0;        // 当前报的数
        
        // 找到第m个未出圈的人
        while(num < m) {
            if(!people[current]) {  // 如果这个人还在圈内
                num++;             // 报数加1
                if(num == m) {     // 如果报到m
                    printf("%3d", current + 1);  // 输出这个人的编号（转回1-based）
                    people[current] = 1;         // 标记为已出圈
                    count++;                     // 出圈人数加1
                    if(count < n) printf("");    // 如果不是最后一个人，输出空格
                }
            }
            current = (current + 1) % n;  // 移动到下一个位置
        }
    }
    printf("\n");
    
    return 0;
}