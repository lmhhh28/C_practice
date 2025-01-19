#include <stdio.h>

int main()
{
    const char *s[] = 
    {
        "January,31",
        "February,28/29","March,31",
        "April,30",
        "May,31",
        "June,30",
        "July,31",
        "August,31",
        "September,30",
        "October,31",
        "November,30",
        "December,31",
    };
    int i;
    scanf("%d",&i);
    printf("%s\n",s[i-1]);
}