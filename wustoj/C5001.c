#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }
    int temp = a[0];
    for(int i = 1;i < n;i ++)
    {
        if(a[i] > temp)
        {
            temp = a[i];
        }
    }
    printf("%d\n",temp);
}
//O(n)
