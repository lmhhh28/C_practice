#include <stdio.h>

int transform(int *num);

int main()
{
    int num,i = 1;
    scanf("%d",&num);
    int num_temp = num;
    while(num_temp != transform(&num))
    {
        //transform(&num);
        printf("%d:%d\n",i,num);
        i ++;
        num_temp = num;
    }
    printf("%d:%d\n",i,num);
}

int transform(int *num)
{
    int sum = 0;
    while(*num > 0)
    {
        sum = sum + *num % 10;
        *num = *num / 10;
    }
    *num = sum * 3 + 1;
    return *num;
}