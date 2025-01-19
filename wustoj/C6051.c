#include <stdio.h>
#include <string.h>

// 将8位二进制字符串转换为十进制数
int bin_to_dec(char *bin) {
    int result = 0;
    for(int i = 0; i < 8; i++) {
        result = result * 2 + (bin[i] - '0');
    }
    return result;
}

int main() {
    char ip[33];  // 32位二进制 + 结束符
    char temp[9]; // 8位二进制 + 结束符
    
    // 读取32位二进制IP地址
    scanf("%s", ip);
    
    // 每8位转换一次，共转换4次
    for(int i = 0; i < 4; i++) {
        // 复制8位到临时数组
        strncpy(temp, ip + i * 8, 8);
        temp[8] = '\0';
        
        // 转换并输出
        printf("%d", bin_to_dec(temp));
        
        // 除了最后一个数，后面都要加点
        if(i < 3) printf(".");
    }
    printf("\n");
    
    return 0;
}