#include <stdio.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == X) {
            printf("%d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not Found\n");
    }

    return 0;
}
