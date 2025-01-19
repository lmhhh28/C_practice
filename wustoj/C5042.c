#include <stdio.h>

int factornum(int num);
void factor(int num,int *s);

int main()
{
    int m,n,count = 0;
    scanf("%d %d",&m,&n);
    for(int i = m;i <= n;i ++)
    {
        int factornum_ = factornum(i),sum = 0,flag = 0;
        int s[factornum_];
        factor(i,s);
        for(int j = 0;j < factornum_;j ++)
        {
            sum += s[j];
        }
        if(sum == i)
        {
            printf("%d = ",i);
            if(flag == 0)
            {
                printf("%d",s[factornum_ - 1]);
                flag = 1;
            }
            if(flag == 1)
            {
                for(int j = factornum_ - 2;j >= 0;j --)
                {
                    printf(" + %d",s[j]);
                }
            }
            printf("\n");
            count ++;
        }
        
        
    }
    if(count == 0)
    {
        printf("None\n");
    }
}

int factornum(int num)
{
    int count = 0;
    for(int i = num - 1;i > 0;i --)
    {
        if(num % i == 0)
        {
            count ++;
        }
    }
    return count;
}

void factor(int num,int *s)
{
    int count = 0;
    for(int i = num - 1;i > 0;i --)
    {
        if(num % i == 0)
        {
            s[count ++] = i;
        }
    }
}

