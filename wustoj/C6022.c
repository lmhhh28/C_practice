#include <stdio.h>
#include <string.h>

int main() {
    char str[101];  // 原始字符串
    char target;    // 要删除的字符
    int j = 0;      // 新字符串的索引
    
    // 读取原始字符串
    gets(str);
    
    // 读取要删除的字符
    scanf("%c", &target);
    
    // 遍历字符串，跳过目标字符
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != target) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';  // 添加字符串结束符
    
    // 输出结果
    printf("%s\n", str);
    
    return 0;
}