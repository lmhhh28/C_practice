#include <stdio.h>

#define MAX_EXP 10000

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int result[MAX_EXP + 1] = {0};
        int A, B;
        
        scanf("%d", &A);
        for (int i = 0; i < A; i++) {
            int exp, coeff;
            scanf("%d %d", &exp, &coeff);
            result[exp] += coeff;
        }
        
        scanf("%d", &B);
        for (int i = 0; i < B; i++) {
            int exp, coeff;
            scanf("%d %d", &exp, &coeff);
            result[exp] += coeff;
        }
        
        int is_first = 1;
        for (int exp = 0; exp <= MAX_EXP; exp++) {
            int coeff = result[exp];
            if (coeff == 0) continue;
            
            char sign = '\0';
            int abs_coeff;
            
            if (is_first) {
                if (coeff < 0) {
                    sign = '-';
                    abs_coeff = -coeff;
                } else {
                    abs_coeff = coeff;
                }
                is_first = 0;
            } else {
                if (coeff < 0) {
                    sign = '-';
                    abs_coeff = -coeff;
                } else {
                    sign = '+';
                    abs_coeff = coeff;
                }
            }
            if (sign != '\0') {
                putchar(sign);
            }
            if (exp == 0) {
                printf("%dx^0", abs_coeff);
            } else {
                if (abs_coeff == 1) {
                    printf("x^%d", exp);
                } else {
                    printf("%dx^%d", abs_coeff, exp);
                }
            }
        }
        
        if (is_first) {
            printf("0");
        }
        printf("\n");
    }
    
    return 0;
}
