#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int numbers[10000];
    double avg = 0.0, msd = 0.0;
    
    // 读取数据个数
    scanf("%d", &n);
    
    // 读取数据并计算总和
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    
    // 计算平均值
    avg = sum / (double)n;
    
    // 计算差的平方和
    double square_sum = 0.0;
    for(int i = 0; i < n; i++) {
        double diff = (double)numbers[i] - avg;
        square_sum += (diff * diff);
    }
    
    // 计算均方差：平方和除以n后开平方根
    msd = sqrt(square_sum / (double)n);
    
    // 输出结果，保留5位小数
    printf("%.5lf\n", msd);
    
    return 0;
}