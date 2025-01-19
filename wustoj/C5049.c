#include <stdio.h>

long long gcd(long long x,long long y);
void app(long long *numerator,long long *denominator);

int main()
{
    long long numerator,denominator;
    scanf("%lld/%lld",&numerator,&denominator);
    app(&numerator,&denominator);
    printf("%lld/%lld\n",numerator,denominator);
}

long long gcd(long long x,long long y)
{
    while(y^=x^=y^=x%=y);
    return x;
}

void app(long long *numerator,long long *denominator)
{
    long long x = gcd(*numerator,*denominator);
    *numerator /= x;
    *denominator /= x;
}
    