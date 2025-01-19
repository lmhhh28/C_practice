#include <stdio.h>
#define Ra 9
#define To 3

int main()
{
    int Ra_s = 0,To_s = 0,time,count = 0;
    scanf("%d",&time);
    while(count < time)
    {
        if(Ra_s > To_s)
        {
            for(int i = 0;i < 30 && count < time;i ++)
            {
                To_s = To_s + To;
                count ++;
            }
        }
        else
        {
            for(int i = 0;i < 10 && count < time;i ++)
            {
                To_s = To_s + To;
                Ra_s = Ra_s + Ra;
                count ++;
            }
        }
    }
    if(Ra_s > To_s)
    {
        printf("^_^ %d\n",Ra_s);
    }
    else if(Ra_s < To_s)
    {
        printf("@_@ %d\n",To_s);
    }
    else
    {
        printf("-_- %d\n",Ra_s);
    }
}