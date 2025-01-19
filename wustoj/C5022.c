#include <stdio.h>
#include <math.h>

int Get_digit_num(int num);
int Get_one_num(int num,int digit_num,int ori_num);
void Pri_quo_num(int num,int digit_num,int ori_num);

int main()
{
    int num,one_num,quo;
    scanf("%d",&num);
    int num_ = num,ret = 1;
    while(num_ > 0)
    {
        int digit = num_ % 10;
        if(digit != 1)
        {
            ret = 0;
            break;
        }
        num_ = num_ / 10;
    }
    if(ret == 1)
    {
        one_num = Get_digit_num(num);
        printf("1 %d\n",one_num);
    }
    else
    {
        int digit_num = Get_digit_num(num),ori_num = 0;
        for(int i = 0;i <= digit_num;i ++)
        {
            ori_num = ori_num + pow(10,i);
        }
        one_num = Get_one_num(num,digit_num,ori_num);
        Pri_quo_num(num,digit_num,ori_num);
        printf(" %d\n",one_num);
    }
}

int Get_digit_num(int num)
{
    int digit = 0;
    while(num > 0)
    {
        num = num / 10;
        digit ++; 
    }
    return digit;
}

int Get_one_num(int num,int digit_num,int ori_num)
{
    if(ori_num % num == 0)
    {
        return digit_num + 1;
    }
    else
    {
        return Get_one_num(num,digit_num,10 * (ori_num % num) + 1) + 1;
    }
}

void Pri_quo_num(int num,int digit_num,int ori_num)
{
    int quo;
    while(ori_num % num != 0)
    {
        quo = ori_num / num;
        //printf("%d %d\n",quo,ori_num);
        ori_num = 10 * (ori_num % num) + 1;
        printf("%d",quo);
    }
    quo = ori_num / num;
    printf("%d",quo);
}