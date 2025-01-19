#include <stdio.h>

int main()
{
    int hour,min,second;
    char s[] = "AM";
    scanf("%d %d %d",&hour,&min,&second);
    if(hour >= 12)
    {
        s[0] = 'P';
    }
    printf("%d %d %d %s\n",hour % 12,min,second,s);
}
