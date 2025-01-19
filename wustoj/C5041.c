#include <stdio.h>
#include <math.h>

int IsPrime(int N);

int main()
{
    int n,count = 0;
    scanf("%d",&n);
    for(int i = 2;i <= n;i ++)
    {
        if(IsPrime(pow(2,i) - 1) == 1)
        {
            printf("%d\n",(int)pow(2,i) - 1);
            count ++;
        }
    }
    if(count == 0)
    {
        printf("None\n");
    }
}

int IsPrime(int N)
{
    int ret = 1;
    for(int i = 2;i < sqrt(N);i ++)
    {
        if(N % i == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}


