#include <stdio.h>

int digit_sum(int num);

int main()
{
    int m,n,count = 0;
    scanf("%d %d",&m,&n);
    for(int i = m;i <= n;i ++)
    {
        int j = 1,ret = 1,sum_temp = digit_sum(i * j);
        for(;j < 10;j ++)
        {
            int sum = digit_sum(i * j);
            if(sum_temp != sum)
            {
                ret = 0;
                break;
            }
        }
        if(ret == 1)
        {
            printf("%d(%d)\n",i,sum_temp);
            count ++;
        }
    }
    if(count == 0)
    {
        printf("None\n");
    }
}

int digit_sum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}