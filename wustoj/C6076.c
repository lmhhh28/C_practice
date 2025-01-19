#include <stdio.h>

int main() {
    int m, n;
    int curr[9][9] = {0};    // 当前状态
    int next[9][9] = {0};    // 下一天的状态
    
    // 读取初始细菌数和天数
    scanf("%d %d", &m, &n);
    
    // 初始化中心位置的细菌数量
    curr[4][4] = m;
    
    // 模拟n天的繁殖过程
    for(int day = 0; day < n; day++) {
        // 清空next数组
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                next[i][j] = 0;
            }
        }
        
        // 处理每个位置的细菌繁殖
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(curr[i][j] > 0) {
                    // 每个细菌产生10个后代
                    long long total = (long long)curr[i][j] * 10;
                    
                    // 2个留在原位置
                    next[i][j] += (int)(total * 2 / 10);
                    
                    // 计算每个方向分配的数量（确保8个方向平均分配）
                    int each = (int)(total * 8 / 10 / 8);
                    
                    // 八个方向的偏移量
                    int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
                    int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
                    
                    // 向八个方向分配
                    for(int k = 0; k < 8; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        
                        if(ni >= 0 && ni < 9 && nj >= 0 && nj < 9) {
                            next[ni][nj] += each;
                        }
                    }
                }
            }
        }
        
        // 将next复制到curr
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                curr[i][j] = next[i][j];
            }
        }
    }
    
    // 输出最终结果
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d", curr[i][j]);
            if(j < 8) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}