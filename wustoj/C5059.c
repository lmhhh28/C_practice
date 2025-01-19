#include <stdio.h>

int IsPrime(int num);

int main()
{
    int num,count = 0,flag = 0;
    scanf("%d",&num);
    int i = num - 1;
    while(count < 10)
    {
        if(i < 2)
        {
            break;
        }
        else if(IsPrime(i) == 1)
        {
            if(flag == 0)
            {
                printf("%d",i);
                flag = 1;
            }
            else
            {
                printf(" %d",i);
            }
            count ++;
        }
        i --;
    }
    printf("\n");
}

int IsPrime(int num)
{
    int ret = 1;
    if(num <= 1)
    {
        ret = 0;
    }
    else
    {
        for(int i = 2;i <= num / i;i ++)
        {
            if(num % i == 0)
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}