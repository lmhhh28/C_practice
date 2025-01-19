#include <stdio.h>

void Run_step(int *arr,int hole_num,int loop_num);

int main()
{
    int hole_num,loop_num,count = 0,flag = 0;
    scanf("%d %d",&hole_num,&loop_num);
    int arr[hole_num];
    for(int i = 0;i < hole_num;i ++)
    {
        arr[i] = 0;
    }
    Run_step(arr,hole_num,loop_num);
    /*
    for(int i = 0;i < hole_num;i ++)
    {
        printf("%d\n",arr[i]);
    }
    */
    for(int i = 1;i < hole_num;i ++)
    {
        if(arr[i] == 0)
        {
            if(flag == 0)
            {
                printf("%d",i);
                flag = 1;
            }
            else
            {
                printf(" %d",i);
            }
            count ++;
        }
    }
    if(arr[0] == 0)
    {
        if(flag == 0)
        {
            printf("%d",hole_num);
            flag = 1;
        }
        else
        {
            printf(" %d",hole_num);
        }
        count ++;
    }
    if(count == 0)
    {
        printf("No choice");
    }
    printf("\n");
}

void Run_step(int *arr,int hole_num,int loop_num)
{
    for(int i = 1;i * (i + 1) <= 2 * hole_num * loop_num + 1;i ++)
    {
        arr[i * (i + 1) / 2 % hole_num] ++;
    }
}

