#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

int main() {
    char a[1001], b[1001], result[1002];
    int carry = 0;  // 进位
    int i = 0, j = 0, k = 0;  // 初始化索引变量
    
    // 读取两个数
    scanf("%s", a);
    scanf("%s", b);
    
    // 将字符串反转，便于从低位开始计算
    reverse(a);
    reverse(b);
    
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // 从低位开始相加
    while(i < len_a || j < len_b || carry) {
        int sum = carry;
        if(i < len_a) sum += a[i] - '0';
        if(j < len_b) sum += b[j] - '0';
        
        result[k++] = sum % 10 + '0';
        carry = sum / 10;
        
        if(i < len_a) i++;
        if(j < len_b) j++;
    }
    result[k] = '\0';
    
    // 反转结果并输出
    reverse(result);
    printf("%s\n", result);
    
    return 0;
}