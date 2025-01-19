#include <stdio.h>

int main()
{
   int num;
   scanf("%03d",&num);
   while(num > 0)
   {
    printf("%d",num % 10);
    num = num / 10;
   }
}