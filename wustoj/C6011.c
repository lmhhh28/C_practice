#include <stdio.h>
#include <ctype.h>

// 判断字符是否为十六进制字符
int isHexChar(char c) {
    return (c >= '0' && c <= '9') || 
           (c >= 'a' && c <= 'f') || 
           (c >= 'A' && c <= 'F');
}

// 将十六进制字符转换为对应的数值
int hexCharToInt(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'a' && c <= 'f') return c - 'a' + 10;
    if(c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

int main() {
    char input[80], hex[8];
    char c;
    int i = 0, j = 0;
    long long decimal = 0;
    
    // 读取字符直到遇到#
    while((c = getchar()) != '#' && i < 79) {
        input[i++] = c;
    }
    input[i] = '\0';
    
    // 提取十六进制字符
    for(i = 0; input[i] != '\0' && j < 8; i++) {
        if(isHexChar(input[i])) {
            hex[j++] = input[i];
        }
    }
    hex[j] = '\0';
    
    // 输出十六进制字符串
    printf("String:%s\n", hex);
    
    // 转换为十进制
    for(i = 0; hex[i] != '\0'; i++) {
        decimal = decimal * 16 + hexCharToInt(hex[i]);
    }
    
    // 输出十进制结果
    printf("number=%lld\n", decimal);
    
    return 0;
}