#include <stdio.h>

void swap(int *a,int *b);
void sort(int *p,int n);

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    for(int i = 0;i < n;i ++)
    {
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *p,int n)
{
    for(int i = 0;i < n;i ++)
    {
        for(int j = 1;j < n - i;j ++)
        {
            if(*(p + i) > *(p + i + j))
            {
                swap((p + i),(p + i + j));
            }
        }
    }
}