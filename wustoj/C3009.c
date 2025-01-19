#include <stdio.h>

int main()
{
    double a;
    int b;
    char c;
    double d;
    scanf("%lf %d %c %lf",&a,&b,&c,&d);
    printf("%c %d %.2lf %.2lf\n",c,b,a,d);
}