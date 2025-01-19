#include <stdio.h>

int main() {
    int N, num;
    int A1 = 0;    
    int A2 = 0;    
    int A3_sum = 0;  
    int A3_count = 0;  
    int hasA1 = 0;    

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num % 3 == 0) {  
            if (!hasA1) {
                A1 = num;
                hasA1 = 1;
            } else if (num > A1) {
                A1 = num;
            }
        } else if (num % 3 == 1) {  
            A2++;
        } else if (num % 3 == 2) {  
            A3_sum += num;
            A3_count++;
        }
    }

    if (hasA1) {
        printf("%d ", A1);
    } else {
        printf("NONE ");
    }

    if (A2 > 0) {
        printf("%d ", A2);
    } else {
        printf("NONE ");
    }

    if (A3_count > 0) {
        printf("%.1f\n", (float)A3_sum / A3_count);
    } else {
        printf("NONE\n");
    }

    return 0;
}
