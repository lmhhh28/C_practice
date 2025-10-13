#include <stdio.h>
#define MAX 10000
int main() {
    int len, pos; int list[MAX]; 
    scanf("%d", &len);
    for(int i = 0; i < len; ++i) {
        scanf("%d", list + i);
    }
    scanf("%d", &pos);
    if(pos < 1 || pos > len) {
        printf("错误：不存在这个元素。\n");
    } else {
        for(int i = pos; i < len; ++i) {
            list[i-1] = list[i];
        }
        --len;
    }
    for(int i = 0; i < len; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}