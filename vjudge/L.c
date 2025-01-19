#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,*b;int num,lenth,count;
    scanf("%d",&num);
    for(int i = 0;i < num;i ++){
        count = 0;
        scanf("%d",&lenth);
        a = (int*)malloc(lenth * sizeof(int));
        b = (int*)malloc(lenth * sizeof(int));
        for(int i = 0;i < lenth;i ++)
            scanf("%d",a + i);
        for(int i = 0;i < lenth;i ++)
            scanf("%d",b + i);
        for(int i = 0,j = 0;i < lenth;i ++){
            for(;j < lenth;j ++){
                if(a[i] > b[j]) count ++;
                else{
                    j ++;
                    break;
                }
            }
            if(j == lenth)  break;
        }
        printf("%d\n",count);
        free(a);free(b);
    }
}