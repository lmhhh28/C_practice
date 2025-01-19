#include <stdio.h>

long long Sum(long long n);

int main()
{
    long long n,m,flag_left = 0,flag_right = 0;
    scanf("%d",&n);
    for(m = n + 1;;m ++)
    {
        if(2 * Sum(m) == Sum(m - n - 1) + Sum(m + n))
        {
            break;
        }
    }
    for(int i = m - n;i <= m;i ++)
    {
        if(flag_left == 1)
        {
            printf(" + %d^2",i);
        }
        else
        {
            printf("%d^2",i);
            flag_left = 1;
        }
    }
    printf(" = ");
    for(int i = m + 1;i <= m + n;i ++)
    {
        if(flag_right == 1)
        {
            printf(" + %d^2",i);
        }
        else
        {
            printf("%d^2",i);
            flag_right = 1;
        }
    }
    printf("\n");
}

long long Sum(long long n)
{
    return n * (n + 1) * (2 * n + 1);
}