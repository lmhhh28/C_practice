#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n;
  
    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic( int number )
{
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
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void PrintN( int m, int n )
{
    for(int i = m + 1;i < n;i ++)
    {
        if(narcissistic(i) == 1)
        {
            printf("%d\n",i);
        }
    }
}