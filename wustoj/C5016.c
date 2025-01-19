#include <stdio.h>
#include <math.h>

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
    long long n,x,integer;
    scanf("%lld",&n);
    struct fraction fract[n];
    for(int i = 0;i < n;i ++)
    {
        scanf("%lld/%lld",&fract[i].numerator,&fract[i].denominator);
        app(&fract[i]);
    }
    for(int i = 1;i < n;i ++)
    {
        add(&fract[0],&fract[i]);
    }
    x = abs(gcd(fract[0].numerator,fract[0].denominator));
    integer = fract[0].numerator / fract[0].denominator;
    if(fract[0].denominator == 1)
    {
        printf("%lld\n",fract[0].numerator);
    }
    else if(integer == 0)
    {
        printf("%lld/%lld\n",fract[0].numerator,fract[0].denominator);
    }
    else
    {
        printf("%lld %lld/%lld\n",integer,fract[0].numerator % fract[0].denominator,fract[0].denominator);
    }
    
}

long long gcd(long long x,long long y)
{
    while(y^=x^=y^=x%=y);
    return x;
}

void app(struct fraction *p)
{
    long long x = abs(gcd(p -> numerator,p -> denominator));
    p -> numerator /= x;
    p -> denominator /= x;
    //printf("%lld %lld\n",p -> numerator,p ->denominator);
}

void add(struct fraction *p,struct fraction *q)
{
    p -> numerator = (p -> numerator) * (q -> denominator) + (p -> denominator) * (q -> numerator);
    p -> denominator *= q -> denominator;
    app(p);
}



