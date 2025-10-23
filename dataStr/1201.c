#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int S1[N], S2[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &S1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &S2[i]);
    }
    
    int i = 0, j = 0;
    int median = 0;
    for (int count = 0; count < N; count++) {
        if (i < N && (j >= N || S1[i] <= S2[j])) {
            median = S1[i];
            i++;
        } else {
            median = S2[j];
            j++;
        }
    }
    printf("%d\n", median);
    return 0;
}
