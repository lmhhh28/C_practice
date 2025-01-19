#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int count = 0; 
    int first = 1; 

    for (int i = m; i <= n; i++) {
        
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 4) {
            if (first) {
                printf("%d", i); 
                first = 0; 
            } else {
                printf(" %d", i); 
            }
            count++;
        }
    }

    
    if (count == 0) {
        printf("total=0");
    }

    
    else
    {
        printf("\ntotal=%d\n", count);
    }

    return 0;
}