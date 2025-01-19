#include <stdio.h>

void factor(int num,int *s);
int factornum(int num);

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int acount = factornum(a),bcount = factornum(b);
    int a_[acount],b_[bcount];
    factor(a,a_);factor(b,b_);
    for(int i = 0;i < acount;i ++)
    {
        int j = 0;
        for(;j < bcount;j ++)
        {
            if(*(a_ + i) == *(b_ + j))
            {
                printf("%d\n",*(a_ + i));
                i = acount;
                break;
            }
        }
    }
}

int factornum(int num)
{
    int count = 0;
    for(int i = num;i > 0;i --)
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
    for(int i = num;i > 0;i --)
    {
        if(num % i == 0)
        {
            s[count ++] = i;
        }
    }
}


