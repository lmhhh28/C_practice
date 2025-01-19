#include <stdio.h>

struct fraction
    {
        double numerator;
        double denominator;
    };

void add(struct fraction *p,struct fraction *q);



int main()
{
    int n;
    scanf("%d",&n);
    struct fraction fract[n];
    for(int i = 0;i < n;i ++)
    {
        fract[i].numerator = 1;
        scanf("%lf",&fract[i].denominator);
    }
    for(int i = 1;i < n;i ++)
    {
        add(&fract[0],&fract[i]);
    }
    //printf("%lf %lf\n",fract[0].numerator,fract[0].denominator);
    printf("%.2lf\n",(double)n * fract[0].denominator / fract[0].numerator);
}

void add(struct fraction *p,struct fraction *q)
{
    p -> numerator = (p -> numerator) * (q -> denominator) + (p -> denominator) * (q -> numerator);
    p -> denominator *= q -> denominator;
}


