#include <stdio.h>

void divide(int *x,int *y,int *z);
int main()
{
    int a[6];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(int i = 0;i < 3;i ++)
    {
        divide(&a[i],&a[i + 1],&a[i + 2]);
        a[i + 3] = a[i];
    }
    printf("%d %d %d\n",a[3],a[4],a[2]);
}

void divide(int *x,int *y,int *z)
{
    *x = *x / 3;
    *y = *y + *x;
    *z = *z + *x;
}