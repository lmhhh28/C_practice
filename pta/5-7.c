#include <stdio.h>
#include <math.h>


double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

double funcos( double e, double x )
{   
    double a = 0;
    for(int i = 0;;i ++)
    {   
        double n = 1;
        for(int j = 1;j <= 2 * i;j ++)
        {
            n = n * j;
        }
        long double b = 1,c = 1;
        for(int j = 1;j <= i;j ++)
        {
            b = b * -1;
        }
        for(int j = 1;j <= 2 * i;j ++)
        {
            c = c * x;
        }
        a = a + (b * c / n); 
        if(c / n < e)
        {
            break;
        }
    }
    return a;
}