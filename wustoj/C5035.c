#include <stdio.h>

int power(int a,int n);
int nar(int N,int num);

int main()
{
    int N;
    scanf("%d",&N);
    for(int i = power(10,N - 1);i < power(10,N);i ++)
    { 
        if(nar(N,i) == 1)
        {
            printf("%d\n",i);
        }
    }
   
}

int power(int a,int n)
{
    int res = 1;
    for(int i = 0;i < n;i ++)
    {
        res *= a;
    }
    return res;
}

int nar(int N,int num)
{
    int num_[N],Num = num,i = 0,sum = 0;
    while(num > 0)
    {
        num_[i] = num % 10;
        sum += power(num_[i ++],N);
        num = num / 10; 
    }
    if(Num == sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}