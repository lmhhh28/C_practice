#include <stdio.h>

void max(int* p,int *q);

int main()
{
    int a,b,c,d,count;
    scanf("%d",&count);
    for(int i = 0;i < count;i ++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        max(&a,&b);max(&c,&d);
        printf("%s\n",((c > a && c < b) && (d > b && d <=12)) || ((c >= 0 && c < a) && (d > a && d < b)) ? "YES" : "NO");
    }
}

void max(int *p,int *q)
{
    int temp;
    if(*p > *q){
        temp = *p;
        *p = *q;
        *q = temp;
    }
}