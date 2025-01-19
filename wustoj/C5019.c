#include <stdio.h>
#include <math.h>

int IsPrime(int N);

int main()
{
    long long num,start_temp;
    int count_temp = 0,flag = 0;
    scanf("%lld",&num);
    for(long long i = 2;i <= sqrt(num);i ++)
    {
        long long num_ = num,start = i;
        int count = 0;
        for(long long j = i;num_ % j == 0;j ++)
        {
            count ++;
            num_ = num_ / j;
        }
        if(count > count_temp)
        {
            count_temp = count;
            start_temp = start;
        }
    }
    if(IsPrime(num) == 0)
    {
        printf("%d\n",count_temp);
        for(long long i = start_temp;i < start_temp + count_temp;i ++)
        {
            if(flag == 1)
            {
                printf("*%lld",i);            
            }
            else
            {
                printf("%lld",i);
                flag = 1;
            }
        }
        printf("\n");
    }
    else
    {
        printf("%d\n%lld\n",1,num);
    }
    
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