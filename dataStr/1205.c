#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    
    int *L1 = (int*)malloc(n1 * sizeof(int));
    int *L2 = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        scanf("%d", &L1[i]);
    for (int i = 0; i < n2; i++)
        scanf("%d", &L2[i]);
    
    int *S = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
        S[i] = L2[i];
    
    qsort(L1, n1, sizeof(int), cmp);
    qsort(S, n2, sizeof(int), cmp);
    
    int *L3 = (int*)malloc(n1 * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < n1; i++) {
        int found = 0;
        for (int j = 0; j < n2; j++) {
            if (L1[i] == S[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            L3[count++] = L1[i];
        }
    }
    
    if (count == 0) {
        printf("0");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", L3[i]);
        }
    }
    
    free(L1);
    free(L2);
    free(S);
    free(L3);
    
    return 0;
}

