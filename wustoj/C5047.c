#include <stdio.h>
#include <math.h>

int IsPrime(int n);
int Prime(int n);

int main()
{
    int num,flag = 0;scanf("%d",&num);
    printf("%d=",num);
    for(int i = 1;;i ++)
    {
        while(num % Prime(i) == 0)
        {
            if(flag == 1)
            {
                printf("*%d",Prime(i));
                num = num / Prime(i);
            }
            if(flag == 0)
            {
                printf("%d",Prime(i));
                num = num / Prime(i);
                flag = 1;
            }
        }
        if(num == 1)
        {
            break;
        }
    }
    printf("\n");
}

int IsPrime(int n)
{
    int ret = 1;
    for(int i = 2;i <= sqrt(n);i ++) 
    {
        if(n % i == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}

int Prime(int n)
{
    int count = 0;
    for(int i = 2;;i ++)
    {
        if(IsPrime(i) == 1)
        {
            count ++;
        }
        if(count == n)
        {
            return i;
            break;
        }
    }
    
}