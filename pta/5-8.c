#include <stdio.h>

void hollowPyramid ( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    hollowPyramid ( n );

    return 0;
}

void hollowPyramid(int n)
{
    if(n == 1)
    {
        printf("%d\n",1);
    }
    else
    {
        for(int i = 1;i <= n - 1;i ++)
        {
                printf(" ");
        }
        printf("%d\n",1);
        for(int i = 2;i < n;i ++)
        {
            for(int j = 1;j <= n - i;j ++)
            {
                printf(" ");
            }
            printf("%d",i);
            for(int j = 1;j <= 2 * i - 3;j ++)
            {
                printf(" ");
            }
            printf("%d\n",i);
        }
        for(int i = 1;i <= 2 * n - 1;i ++)
        {
            printf("%d",n);
        }
        printf("\n");
    }
}