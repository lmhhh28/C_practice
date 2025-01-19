#include <stdio.h>

int main()
{
    int n,ret = 1;
    scanf("%d",&n);
    if(n == 2)
    {
        ret = 1;
    }
    else if(n == 1)
    {
        ret = 0;
    }
    else
    {
        for(int i = 2;i < n;i ++)
        {
            if(n % i == 0)
            {
                ret = 0;
                break;
            }
        }
    }
    if(ret == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}