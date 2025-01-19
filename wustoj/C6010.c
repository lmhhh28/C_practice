#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[100][80];  // 可以存储100个字符串，每个最长79字符
    char max_str[80];   // 存储最大的字符串
    
    // 读取字符串个数
    scanf("%d", &n);
    getchar();  // 读取换行符
    
    // 读取所有字符串
    for(int i = 0; i < n; i++) {
        gets(str[i]);
        
        // 如果是第一个字符串或当前字符串大于max_str
        if(i == 0 || strcmp(str[i], max_str) > 0) {
            strcpy(max_str, str[i]);
        }
    }
    
    // 输出最大字符串
    printf("%s\n", max_str);
    
    return 0;
}