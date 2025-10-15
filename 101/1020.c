#include <stdio.h>
#include <string.h>

int trans(char* buffer, int* muti, int* len) {
    int state = buffer[0] == '-' ? 1 : 0;
    int begin = *len-1;
    *len = state ? begin : *len;
    for(int i = begin, j = 0; i >= state; --i, ++j) {
        muti[j] = state ? '0'-buffer[i] : buffer[i]-'0';
    }
    return state;
}

int main() {
    char buffer1[1001], buffer2[1001];
    scanf("%s%s", buffer1, buffer2);
    int len1 = strlen(buffer1), len2 = strlen(buffer2);
    int muti1[1001] = {0}, muti2[1001] = {0}, res[2002] = {0};
    int state1 = trans(buffer1, muti1, &len1);
    int state2 = trans(buffer2, muti2, &len2);
    int state = state1^state2;
    for(int i = 0; i < len2; ++i) {
        for(int j = 0; j < len1; ++j) {
            res[i+j] += muti2[i]*muti1[j];
            res[i+j+1] += res[i+j]/10;
            res[i+j] %= 10;
        }
    }
    int len = len1 + len2;
    while(res[len-1] == 0 && len > 0 ) {
        --len;
    }
    if(len > 1000) {
        printf("错误：位数超限。\n");
    } else {
        if(!len) {
            printf("0");
        } else {
            if(state) {
                printf("-");
            }
            for(int i = len-1; i >=0; --i) {
                printf("%d", state ? -res[i] : res[i]);
            }
        }
    }
    return 0;
}