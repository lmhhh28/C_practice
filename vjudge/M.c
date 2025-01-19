#include <stdio.h>
#include <stdlib.h>

int Trans(int num,int* p);

int main()
{
    int* arr;int num,count;
    scanf("%d",&count);
    for(int i = 0;i < count; i ++){
        scanf("%d",&num);
        arr = (int*)malloc((num + 2) * sizeof(int));
        for(int j = 0;j < num;j ++)
            scanf("%lld",arr + j);
        printf("%s\n",Trans(num,arr) == 1 ? "YES" : "NO");
        free(arr);
    }
}

int Trans(int num,int* p){
    int ret = 1;
    for(int i = 0;i < num;i ++){
        while(p[i] > 0)
            p[i] -= 1;p[i + 1] -= 2;p[i + 2] -= 1;
        if(p[i] < 0 || (i == num - 3 && p[num - 1] != 0)){
            ret = 0;
            break;
        }
    }
    return ret;
}