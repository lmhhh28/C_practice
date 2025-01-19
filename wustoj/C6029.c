#include <stdio.h>

int main() {
    int mood[24];    // 存储24小时的心情指数
    int query;       // 查询时间点
    
    // 读取24小时的心情指数
    for(int i = 0; i < 24; i++) {
        scanf("%d", &mood[i]);
    }
    
    // 处理查询
    while(scanf("%d", &query) == 1) {
        // 检查时间点是否合法
        if(query < 0 || query > 23) {
            break;
        }
        
        // 输出查询结果
        printf("%d %s\n", mood[query], 
               mood[query] > 50 ? "Yes" : "No");
    }
    
    return 0;
}