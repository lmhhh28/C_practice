#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int triangle[32][32] = {0};

    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("     ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%10d", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}
