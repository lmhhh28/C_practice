#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N][N];
    int value = 1;
    
    for (int j = 0; j < N; j ++) {
        int x = N - 1 - j;
        int y = 0;
        while (x < N && y <= j) {
            arr[x][y] = value;
            value ++;
            x ++;
            y ++;
        }
    }
    
    for (int i = 1; i < N; i ++) {
        int x = 0;
        int y = i;
        while (x < N - i && y < N) {
            arr[x][y] = value;
            value ++;
            x ++;
            y ++;
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= i; j ++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}