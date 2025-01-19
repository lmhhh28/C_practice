#include <stdio.h>

int main()
{
    char s[11];int i = 0,count = 0;
    scanf("%s",s);
    while(s[i] != '\0')
    {
        if(s[i] % 2 == 0)
        {
            count ++;
        }
        i ++;
    }
    printf("%d\n",count);
}