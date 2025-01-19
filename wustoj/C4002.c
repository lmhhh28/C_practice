#include <stdio.h>

void swap(int *a,int *b);
void sort(int *p,int n);
int main()
{
    int s[3];
    scanf("%d %d %d",&s[0],&s[1],&s[2]);
    sort(s,3);
    printf("a=%d,b=%d,c=%d\n",s[0],s[1],s[2]);
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