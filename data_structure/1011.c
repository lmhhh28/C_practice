#include <stdio.h>
#define MAX 10000
int main() {
    int len, pos, num; int list[MAX];
    scanf("%d", &len);
    for(int i = 0; i < len; ++i) {
        scanf("%d", list + i);
    }
    scanf("%d%d", &pos, &num);
    if(pos > len + 1 || pos < 1) {
        printf("错误：插入位置不合法。\n");
    } else if(len == MAX) {
        printf("错误：表满不能插入。\n");
    } else {
        for(int i = len - 1; i >= pos - 1; --i) {
            list[i+1] = list[i];
        }
        list[pos - 1] = num;
        ++len;
    }
    for(int i = 0; i < len; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}