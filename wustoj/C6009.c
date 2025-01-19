#include <stdio.h>

int main() {
    char str1[101], str2[101];
    int i = 0, j = 0;
    
    // 读取两个字符串
    gets(str1);
    gets(str2);
    
    // 找到str1的末尾
    while(str1[i] != '\0') {
        i++;
    }
    
    // 将str2追加到str1后面
    while(str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';  // 添加字符串结束符
    
    // 输出结果
    printf("%s\n", str1);
    
    return 0;
}
