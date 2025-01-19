#include <stdio.h>

int main() {
    int num, sum = 0;

    while (1) {
        scanf("%d", &num);
        if (num <= 0) {
            break;  
        }
        if (num % 2 != 0) {
            sum += num;  
        }
    }

    printf("%d\n", sum);

    return 0;
}