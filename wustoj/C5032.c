#include <stdio.h>
#include <math.h>

double fact(double n);
//long long binpow(long long a, long long b);

int main()
{
    double n = 0,x,sum = 0;
    scanf("%lf",&x);
    //printf("%lf",pow(x,n) / fact(n));
    while(pow(x,n) / fact(n) >= 0.000001)
    {
        sum += pow(x,n) / fact(n);
        n ++;
    }
    int sum_ = (sum * 1000000 + 5) / 10;
    sum = (double)sum_ / 100000;
    printf("%.5lf\n",sum);
}

double fact(double n)
{
    double fact_ = 1;
    for(int i = 1;i <= n;i ++)
    {
        fact_ *= i; 
    }
    return fact_;
}

/*long long binpow(long long a, long long b) 
{
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}*/