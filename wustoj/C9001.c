#include <stdio.h>

int main()
{
    typedef struct Stu_inf
    {
        char s[17];
        int test_num;
        int exam_num;
    }Stu_inf;
    int N,num;
    scanf("%d",&N);
    Stu_inf stu_[N];
    for(int i = 0;i < N;i ++)
    {
        scanf("%s %d %d",stu_[i].s,&stu_[i].test_num,&stu_[i].exam_num);
    }
    scanf("%d",&num);
    int arr[num];
    for(int i = 0;i < num;i ++)
    {
        scanf("%d",&arr[i]);
    }
    for(int j = 0;j < num;j ++)
    {
        for(int i = 0;i < N;i ++)
        {
            if(arr[j] == stu_[i].test_num)
            {
                printf("%s %d\n",stu_[i].s,stu_[i].exam_num);
            }            
        }
    }

}