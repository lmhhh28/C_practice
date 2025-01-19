#include <stdio.h>

int main()
{
    int N,U,D,sum = 0,count = 0;
    scanf("%d %d %d",&N,&U,&D);
    while(sum < N)
    {
        sum = sum + U;
        count ++;
        if(sum >= N)
        {
            break;
        }
        sum = sum - D;
        count ++;
    }
    printf("%d\n",count);
}