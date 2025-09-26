#include <stdio.h>
#define MAX 10000
int main() {
    int len; scanf("%d", &len);
    int list[MAX];
    for(int i = 0; i < len; ++i) {
        scanf("%d", list + i);
    }
    for(int i = len - 1; i >=0; --i) {
        printf("%d ", list[i]);
    }
    printf("\n");
}