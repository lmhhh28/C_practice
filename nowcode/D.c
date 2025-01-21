#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        if (n % 2 != 0) {
            printf("No\n");
            continue;
        }
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        qsort(arr, n, sizeof(int), compare);
        int count1 = 1, count2 = 0;
        int distinct = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count1++;
            } else {
                distinct++;
                if (distinct > 2) {
                    break;
                }
                count2 = 1;
            }
        }
        if (distinct == 2 && count1 == count2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}