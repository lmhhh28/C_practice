#include <stdio.h>

int main()
{
    double principal,rate;
    scanf("%lf %lf",&principal,&rate);
    printf("%11.2lf\n%11.2lf\n%11.2lf\n",principal,principal * rate / 100,principal + principal * rate / 100);
}