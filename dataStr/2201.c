#include <stdio.h>

int main() {
    int coef, exp;
    int first = 1;
    
    while (scanf("%d %d", &coef, &exp) != EOF) {
        if (exp != 0) {
            if (!first) {
                printf(" ");
            }
            printf("%d %d", coef * exp, exp - 1);
            first = 0;
        }
    }
    
    if (first) {
        printf("0 0");
    }
    
    return 0;
}