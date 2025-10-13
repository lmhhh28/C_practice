#include <stdio.h>
#define MAX 100000
int main() {
    int len; int list[MAX];
    scanf("%d", &len);
    for(int i = 0; i <len; ++i) {
        scanf("%d", list + i);
    }
    int current = 0, max = 0, begin = -1, end = -1;
    for(int i = 0; i < len; ++i) {
        current += list[i];
        if(current < 0) {
            current = 0;
        }
        if(current > max) {
            max = current;
            end = i;
        }
    }
    int sum = 0, pos = 0;
    for(int i = 0; i <= end; ++i) {
        sum += list[i];
    }
    for(; sum != max; ++pos) {
        sum -= list[pos];
    }
    if(end != -1) {
        begin = pos;
    }
    printf("%d\n%d %d", max, begin, end);
    return 0;
}