#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int x, y;
    scanf("%d %d", &x, &y);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < x || arr[i] > y) {
            arr[count++] = arr[i];
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    
    return 0;
}
