#include <stdio.h>

int f(int n);

int main()
{
    int m,n,count = 0;
    scanf("%d %d",&m,&n);
    for(int i = m;i <= n;i ++)
    {
        if(f(i) == 1)
        {
            count ++;
            printf("%d ",i);
        }
    }
    if(count == 0)
    {
        printf("No exist");
    }
    printf("\n");
}

int f(int n)
{
    int sum = 0,ret = 0;
    while(n > 0)
    {
        sum += n % 10;
        if(n % 10 == 5)
        {
            ret = 1;
        }
        n = n / 10;
    }
    if(ret == 1 && sum % 3 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
