#include <stdio.h>
#include <math.h>

int IsPrime(int N);

int main()
{
    int N,i = 2;
    scanf("%d",&N);
    for(;i <= N / 2;i ++)
    {
        if(IsPrime(i) == 1 && IsPrime(N - i) == 1)
        {
            break;
        }
    }
    printf("%d = %d + %d\n",N,i,N - i);
}

int IsPrime(int N)
{
    int ret = 1;
    for(int i = 2;i <= sqrt(N);i ++)
    {
        if(N % i == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}