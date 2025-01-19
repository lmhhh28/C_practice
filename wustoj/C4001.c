#include <stdio.h>

int main()
{   int number;
    scanf("%d",&number);
    int count = 0,a,b,c = 0;
    a = number;
    b = number;
    while(a > 0)
    {
        a = a / 10;
        count ++;
    }
    int d[count];
    while(b > 0)
    {
        for(int i = 0;i < count;i ++)
        {
            d[i] = b % 10;
            b = b / 10;
        }
    }
    for(int j = 0;j < count;j ++)
    {
        int pow = 1;
        for(int k = 0;k < count;k ++)
        {
            pow = pow * d[j];
        }
        c = c + pow;
    }
    if(number == c)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}