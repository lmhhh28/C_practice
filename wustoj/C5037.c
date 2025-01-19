#include <stdio.h>
#include <math.h>
#define BLACKHOLE 495

void swap(int *a,int *b);
void sort(int *p,int n);
void getDigit(int num,int *s);
int rearrMax(int num,int *s);
int rearrMin(int num,int *s);
void transform(int *num,int *s);

int main()
{
    int num,i = 1,s[3] = {0,0,0,};
    scanf("%d",&num);
    getDigit(num,s);
    /*
    for(int j = 0;j < 3;j ++)
    {
        printf("%d\n",s[j]);
    }
    */
    do
    {
        printf("%d: ",i ++);
        transform(&num,s);
        getDigit(num,s);
    }
    while(num != 0 && num != BLACKHOLE);
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *p,int n)
{
    for(int i = 0;i < n;i ++)
    {
        for(int j = 1;j < n - i;j ++)
        {
            if(*(p + i) > *(p + i + j))
            {
                swap((p + i),(p + i + j));
            }
        }
    }
}

void getDigit(int num,int *s)
{
    int i = 0;
    for(int j = 0;j < 3;j ++)
    {
        s[j] = 0;
    }
    while(num > 0)
    {
        s[i ++] = num % 10;
        num = num / 10;
    }
    sort(s,3);
}

int rearrMax(int num,int *s)
{
    int sum = 0;
    for(int i = 0;i < 3;i ++)
    {
        sum = sum + s[i] * pow(10,i);
    }
    return sum;
}

int rearrMin(int num,int *s)
{
    int sum = 0;
    for(int i = 0;i < 3;i ++)
    {
        sum = sum + s[i] * pow(10,2 - i);
    }
    return sum;
}

void transform(int *num,int *s)
{
    printf("%d - %d = %d\n",rearrMax(*num,s),rearrMin(*num,s),rearrMax(*num,s) - rearrMin(*num,s));
    *num = rearrMax(*num,s) - rearrMin(*num,s);
}