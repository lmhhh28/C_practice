#include <stdio.h>
#include <math.h>

int main()
{
    int years;

    scanf("%d", &years);


    double log2 = log10(2); 
    double growth_factor = pow(10, log2 / years); 
    double growth_rate = (growth_factor - 1) * 100; 
    
    
    printf("%.2f%c\n", growth_rate,'%');
    return 0;
}
