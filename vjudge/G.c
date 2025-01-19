#include <stdio.h>

int main()
{
    int count,n,k;
    scanf("%d",&count);
    for(int i = 0;i < count;i ++)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",(n - 1) * k + 1);
    }
}