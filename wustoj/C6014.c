#include <stdio.h>

int main() {
    int n, m;
    char name[100][26];
    int scores[100][10];
    int total[100] = {0};
    double avg[10] = {0};
    
    // 读取学生人数和课程数
    scanf("%d %d", &n, &m);
    
    // 读取每个学生的数据
    for(int i = 0; i < n; i++) {
        scanf("%s", name[i]);
        for(int j = 0; j < m; j++) {
            scanf("%d", &scores[i][j]);
            total[i] += scores[i][j];  // 计算学生总分
            avg[j] += scores[i][j];    // 累加每门课程的分数
        }
    }
    
    // 计算每门课程的平均分
    for(int j = 0; j < m; j++) {
        avg[j] /= n;
    }
    
    // 输出每个学生的成绩
    for(int i = 0; i < n; i++) {
        printf("%-8s%6d", name[i], total[i]);
        for(int j = 0; j < m; j++) {
            printf("%6d", scores[i][j]);
        }
        printf("\n");
    }
    
    // 输出每门课程的平均分
    printf("average score:");
    for(int j = 0; j < m; j++) {
        printf("%6.1f", avg[j]);
    }
    printf("\n");
    
    return 0;
}