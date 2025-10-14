#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, num, m; scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        arr[i] = num;
    }
    scanf("%d", &m); int j = 0, flag = 0;
    for(; j < n; ++j) {
        if(arr[j] == m) {
            flag = 1;
            break;
        }
    }
    if(flag) {
        printf("%d\n", j);
    } else {
        printf("-1\n");
    }
    return 0;
}