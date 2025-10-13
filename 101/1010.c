#include <stdio.h>
#define MAX 10000
int main() {
    int len, num, flag = -1; int list[MAX];
    scanf("%d", &len);
    for(int i = 0; i < len; ++i) {
        scanf("%d", list + i);
    }
    scanf("%d", &num);
    for(int i = 0; i < len; ++i) {
        if(list[i] == num) {
            flag = i;
            break;
        }
    }
    printf("%d\n", flag);
    return 0;
}