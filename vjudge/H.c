#include <stdio.h>

int main()
{
    int large,small,count;
    scanf("%d",&count);
    for(int i = 0;i < count;i ++){
        scanf("%d %d",&small,&large);
        int left = small - (large / 2 * 7 + (large % 2) * 11) < 0 ? 0 : small - (large / 2 * 7 + (large % 2) * 11);
        printf("%d\n",large / 2 + large % 2 + left / 15 + (left % 15 || 0));
    }
}