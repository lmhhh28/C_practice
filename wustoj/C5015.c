#include <stdio.h>
#include <math.h> 

int main() {
    int N;
    char C;
    
    
    scanf("%d %c", &N, &C);
    
    
    int rows = round(N / 2.0);
    
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", C);
        }
        printf("\n");
    }
    
    return 0;
}
