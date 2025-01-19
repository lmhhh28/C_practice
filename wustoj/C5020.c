#include <stdio.h>

int count(int n,int *p_temp,int *s);
int min(int n,int *temp,int *s);
int max(int n,int *temp,int *s);

int main()
{
    int n;scanf("%d",&n);
    int s[n];
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&s[i]);
    }
    int temp_min = s[0],temp_max = s[0];
    int num_min = min(n,&temp_min,s);
    int num_max = max(n,&temp_max,s);
    printf("%d %d\n%d %d\n",temp_min,num_min,temp_max,num_max);

}

int count(int n,int *p_temp,int *s)
{
    int count_ = 0;
    for(int i = 0;i < n;i ++)
    {
        if(s[i] == *p_temp)
        {
            count_ ++;
        }
    }
    return count_;
}

int min(int n,int *p_temp,int *s)
{
    for(int i = 0;i < n;i ++)
    {
        if(s[i] < *p_temp)
        {
            *p_temp = s[i];
        }
    }
    int count_ = count(n,p_temp,s);
    return count_;
}

int max(int n,int *p_temp,int *s)
{
    for(int i = 0;i < n;i ++)
    {
        if(s[i] > *p_temp)
        {
            *p_temp = s[i];
        }
    }
    int count_ = count(n,p_temp,s);
    return count_;

}