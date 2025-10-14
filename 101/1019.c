#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trans(char* buffer, int* add, int* len) {
    int state = 0;
    if(*buffer == '-') {
        state = 1;
    }
    for(int i = *len-1, j = 0; i >= state; --i, ++j) {
        add[j] = buffer[i] - '0';
        if(state) {
            add[j] = -add[j];
        }
    }
    *len -= state;
    return state;
}

int main() {
    char buffer1[1001], buffer2[1001];
    int add1[1001], add2[1001];
    scanf("%s%s", buffer1, buffer2);
    int len1 = strlen(buffer1), len2 = strlen(buffer2);
    printf("%s %s\n%d %d\n", buffer1, buffer2, len1, len2);
    trans(buffer1, add1, &len1);
    trans(buffer2, add2, &len2);
    // for(int i = len1-1; i >= 0; --i) {
    //     printf("%d ", add1[i]);
    // }
    // printf("\n");
    // for(int i = len2-1; i >= 0; --i) {
    //     printf("%d ", add2[i]);
    // }
    int res[1001]; int i = 0, len ;
    for(; i < len1 && i < len2; ++i) {
        res[i] = add1[i] + add2[i];
    }
    if(i >= len1) {
        for(; i < len2; ++i) {
            res[i] = add2[i];
        }
        len = len2;
    } else if(i >= len2) {
        for(; i < len1; ++i) {
            res[i] = add1[i];
        }
        len = len1;
    }
    if((len == 1000 && res[len-1] >= 10) || len > 1000) {
        printf("错误：位数超限。\n");
        return 0;
    }
    for(int i = 0; i < len - 1; ++i) {
        if(res[i] < 0) {
            res[i] += 10;
            --res[i+1];
        } else if(res[i] >= 10) {
            res[i] -= 10;
            ++res[i+1];
        }
    }
    int flag = 0;
    for(int i = len-1; i >= 0; --i) {
        if(res[i]) {
            flag = 1;
        }
        if(flag) {
            printf("%d", res[i]);
        }
    }
    return 0;
}