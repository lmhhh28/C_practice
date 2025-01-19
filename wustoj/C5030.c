#include <stdio.h>

int main()
{
    int amount,count = 0;
    scanf("%d",&amount);

    for (int k = amount / 5;k >= 1;k --)  
    {
        for (int j = (amount - 5 * k) / 2;j >= 1;j --)  
        {
            int i = amount - 5 * k - 2 * j;  
            if (i >= 1)  
            {
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", k, j, i, k + j + i);
                count ++;
            }
        }
    }

    printf("count = %d\n",count);
}
