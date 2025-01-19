#include <stdio.h>

int M, N;
char map[20][20];     // 原始地图
int damage[20][20];   // 记录每个位置受到的伤害

// 检查坐标是否在地图范围内
int is_valid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// 计算一发炮弹的效果并返回消灭的蚊子数
int fire(int x, int y) {
    int killed = 0;
    int dx[] = {0, -1, 0, 1, 0};  // 中心点和四个方向的x偏移
    int dy[] = {0, 0, 1, 0, -1};  // 中心点和四个方向的y偏移
    
    // 先处理中心点
    if(is_valid(x, y) && map[x][y] == '#' && damage[x][y] < 2) {
        killed++;
        damage[x][y] = 2;
    }
    
    // 再处理周围四个点
    for(int i = 1; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!is_valid(nx, ny)) continue;
        
        if(map[nx][ny] == '#' && damage[nx][ny] < 2) {
            damage[nx][ny]++;     // 增加伤害
            if(damage[nx][ny] == 2) {  // 如果这次伤害导致蚊子死亡
                killed++;
            }
        }
    }
    
    return killed;
}

int main() {
    // 读取地图大小
    scanf("%d %d", &M, &N);
    
    // 读取地图
    for(int i = 0; i < M; i++) {
        scanf("%s", map[i]);
    }
    
    // 初始化伤害记录
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            damage[i][j] = 0;
        }
    }
    
    // 读取炮弹数量
    int k;
    scanf("%d", &k);
    
    // 处理每发炮弹
    for(int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", fire(x, y));
    }
    
    return 0;
}