#include <stdio.h>

int main() {
    int n;
    int scores[100];
    int max = 0, min = 100;
    double avg = 0;
    int above_avg = 0;
    
    // 读取学生人数
    scanf("%d", &n);
    
    // 读取分数并计算最大值、最小值和总分
    for(int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
        if(scores[i] > max) max = scores[i];
        if(scores[i] < min) min = scores[i];
        avg += scores[i];
    }
    
    // 计算平均分
    avg /= n;
    
    // 统计超过平均分的人数
    for(int i = 0; i < n; i++) {
        if(scores[i] > avg) {
            above_avg++;
        }
    }
    
    // 输出结果
    printf("%d %d %d\n", max, min, above_avg);
    
    return 0;
}