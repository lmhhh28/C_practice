#include <stdio.h>
#include <string.h>

// 大数加法，结果存在a中
void add(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0;  // 进位
    int i, j;
    
    // 从个位开始相加
    for(i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int sum = carry;
        if(i >= 0) sum += a[i] - '0';
        if(j >= 0) sum += b[j] - '0';
        
        if(i < 0) {  // 需要往前进位
            memmove(a + 1, a, len_a + 1);
            len_a++;
            i = 0;
        }
        
        a[i] = sum % 10 + '0';
        carry = sum / 10;
    }
}

int main() {
    int n;
    char f1[1001] = "1";  // f(n-1)
    char f2[1001] = "1";  // f(n-2)
    char temp[1001];      // 临时存储
    
    scanf("%d", &n);
    
    if(n <= 2) {
        printf("1\n");
        return 0;
    }
    
    // 计算第3项到第n项
    for(int i = 3; i <= n; i++) {
        strcpy(temp, f1);      // 保存f(n-1)
        add(f1, f2);          // f(n-1) = f(n-1) + f(n-2)
        strcpy(f2, temp);     // f(n-2) = 原来的f(n-1)
    }
    
    printf("%s\n", f1);
    
    return 0;
}