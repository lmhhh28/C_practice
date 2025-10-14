#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr+i);
    }
    int maxPos = 0, currentPos = 0, maxLen = 1, currentLen = 1;
    for(int i = 0; i < n-1; ++i) {
        if(arr[i+1] <= arr[i]) {
            currentLen = 1;
            currentPos = i+1;
        } else {
            ++currentLen;
        }
        // printf("%d ", currentLen);
        if(currentLen > maxLen) {
            maxLen = currentLen;
            maxPos = currentPos;
        }
        // printf("%d\n", maxLen);
    }
    int flag = 0;
    for(int i = maxPos, j = 0; j < maxLen; ++i, ++j) {
        if(!flag) {
            printf("%d", arr[i]);
            flag = 1;
        } else {
            printf(" %d", arr[i]);
        }
    }
    return 0;
}