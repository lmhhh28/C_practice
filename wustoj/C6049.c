#include <stdio.h>

// 检查是否回到初始顺序
int check_original(int *cards, int size) {
    for(int i = 1; i <= size; i++) {
        if(cards[i] != i) return 0;
    }
    return 1;
}

// 执行一次洗牌
void shuffle(int *cards, int *temp, int N) {
    // 复制当前序列到临时数组
    for(int i = 1; i <= 2*N; i++) {
        temp[i] = cards[i];
    }
    
    // 执行交叉洗牌
    for(int i = 1; i <= N; i++) {
        cards[2*i-1] = temp[N+i];  // 后半部分的牌放在奇数位置
        cards[2*i] = temp[i];      // 前半部分的牌放在偶数位置
    }
}

int main() {
    int N;
    int cards[20001];  // 存储牌的序列
    int temp[20001];   // 临时数组用于洗牌过程
    
    // 读取N
    scanf("%d", &N);
    
    // 初始化牌的序列
    for(int i = 1; i <= 2*N; i++) {
        cards[i] = i;
    }
    
    // 开始洗牌并计数
    int count = 0;
    do {
        shuffle(cards, temp, N);
        count++;
    } while(!check_original(cards, 2*N));
    
    // 输出结果
    printf("%d\n", count);
    
    return 0;
}