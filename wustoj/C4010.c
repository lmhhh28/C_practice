#include <stdio.h>
#include <math.h> 

int main() {
    double x, y, z;

    
    scanf("%lf", &x);
    
    if (x <= 2.5) {
        y = x * x + 1;
    } else {
        y = x * x - 1;
    }
    
    if(1 <= x && x < 2) 
    {
        z = 3 * x + 5;
    } 
    else if(2 <= x && x < 3)
    {
        z = 2 * sin(x) - 1;
    } 
    else if(3 <= x && x < 5) {
        z = sqrt(1 + x * x);
    } 
    else if(5 <= x && x < 8) {
        z = x * x - 2 * x + 5;
    } 

    
    printf("%lf\n", y);
    printf("%lf\n", z);

    return 0;
}
