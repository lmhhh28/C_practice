#include <stdio.h>
#include <math.h>

int main() {
    int N;
    int found = 0;  // 标记是否找到解

    scanf("%d", &N);

    // 遍历所有可能的X和Y，X从1到sqrt(N)
    for (int X = 1; X * X <= N; X++) {
        for (int Y = X; Y * Y <= N; Y++) {
            if (X * X + Y * Y == N) {
                printf("%d %d\n", X, Y);
                found = 1;  // 找到解
            }
        }
    }

    // 如果没有找到解，输出"No Solution"
    if (!found) {
        printf("No Solution\n");
    }

    return 0;
}