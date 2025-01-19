#include <stdio.h>
#include <math.h>

int main() {
    int x, y1, y2, y3;

    
    scanf("%d %d %d %d", &x, &y1, &y2, &y3);

    
    int sum = y1 + y2 + y3;

    
    int t = (x - sum + 1) / 2; 

    
    if (t < 0) {
        t = 0;
    }

    
    printf("%d\n", t);

    return 0;
}

