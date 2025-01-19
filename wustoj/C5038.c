#include <stdio.h>

int main()
{
    int n,count = 0,flag = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
    {
        flag = 0;
        for(int j = 1;j <= n + 1 - i;j ++)
        {
            if(flag == 0)
            {
                printf("%c",'A' + count);
                flag = 1;
                count ++;
            }
            else
            {
                printf(" %c",'A' + count);
                count ++;
            }
        }
        printf("\n");
    }
}