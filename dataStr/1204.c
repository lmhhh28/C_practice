#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n, pos, val;
        scanf("%d %d %d", &n, &pos, &val);
        
        int arr[101];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = val;
        for (int i = 0; i <= n; i++) {
            printf("%d", arr[i]);
            if (i < n) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
