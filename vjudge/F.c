#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,lenth,count_0 = 0,count_1 = 0,ret = 0;int* arr;
    scanf("%d",&num);
    for(int i = 0;i < num;i ++){
        scanf("%d",&lenth);
        arr = (int*)(malloc(lenth * sizeof(int)));
        count_0 = 0;count_1 = 0;ret = 0;
        for(int j = 0;j < lenth;j ++){
            scanf("%1d",arr + j);
            if(arr[j] == 1){
                ret = 0;
                count_1 ++;
            }
            else if(arr[j] == 0 && ret == 0){
                ret = -1;
                count_0 ++;
            }
        }
        if(count_1 > count_0)
            printf("YES\n");
        else
            printf("NO\n");
        free(arr);
    }
}