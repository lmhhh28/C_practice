#include <stdio.h>
// #include <math.h>

struct fraction
{
    long long numerator;
    long long denominator;
};

long long gcd(long long x,long long y);
void app(struct fraction *p);
void add(struct fraction *p,struct fraction *q);

int main()
{
    struct fraction fract_1,fract_2;
    scanf("%lld/%lld %lld/%lld",&fract_1.numerator,&fract_1.denominator,&fract_2.numerator,&fract_2.denominator);
    app(&fract_1);app(&fract_2);
    add(&fract_1,&fract_2);
    app(&fract_1);
    if(fract_1.numerator % fract_1.denominator == 0)
    {
        printf("%lld\n",fract_1.numerator / fract_1.denominator);
    }
    else
    {
        printf("%lld/%lld\n",fract_1.numerator,fract_1.denominator);
    }
}

long long gcd(long long x,long long y)
{
    while(y^=x^=y^=x%=y);
    return x;
}

void app(struct fraction *p)
{
    // long long x = abs(gcd(p -> numerator,p -> denominator));
    long long x;
    p -> numerator /= x;
    p -> denominator /= x;
}

void add(struct fraction *p,struct fraction *q)
{
    p -> numerator = (p -> numerator) * (q -> denominator) + (p -> denominator) * (q -> numerator);
    p -> denominator *= q -> denominator;
    app(p);
}
