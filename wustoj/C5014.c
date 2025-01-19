#include <stdio.h>
#include "/home/lmhhh/c/lib/.lib.h"

//int digit(int n);
//long long int qpow(int base, int power);

int main()
{
    int m,n,count = 0;
    scanf("%d %d",&m,&n);
    for(int i = m;i <= n;i ++)
    {
        int sqnum = qpow(i,2),digitnum = qpow(10,digit(i));
        if(sqnum % digitnum == i)
        {
            printf("%d ",i);
            count ++;
        }
    }
    if(count == 0)
    {
        printf("No exist\n");
    }
    else
    {
        printf("\n");
    }
}

/*
int digit(int n)
{
    int count = 0;
    while(n > 0)
    {
        n = n / 10;
        count ++;
    }
    return count;
}
*/

 /*
long long int qpow(int base, int power)
{
	long long int result = 1;
	while (power > 0)           //指数大于0进行指数折半，底数变其平方的操作
	{
		if (power & 1)			//指数为奇数，power & 1这相当于power % 2 == 1
			result *= base;     //分离出当前项并累乘后保存
		power >>= 1;			//指数折半,power >>= 1这相当于power /= 2;
		base *= base;           //底数变其平方
	}
	return result;              //返回最终结果
}
*/

