#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    char even[501];  // 存储偶数位置的字符
    int len, even_count = 0;
    
    // 读取字符串
    gets(str);
    len = strlen(str);
    
    // 提取偶数位置的字符
    for(int i = 0; i < len; i += 2) {
        even[even_count++] = str[i];
    }
    
    // 对偶数位置的字符进行冒泡排序
    for(int i = 0; i < even_count - 1; i++) {
        for(int j = 0; j < even_count - 1 - i; j++) {
            if(even[j] > even[j + 1]) {
                char temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }
    
    // 将排序后的字符放回原字符串的偶数位置
    even_count = 0;
    for(int i = 0; i < len; i += 2) {
        str[i] = even[even_count++];
    }
    
    // 输出结果
    printf("%s\n", str);
    
    return 0;
}