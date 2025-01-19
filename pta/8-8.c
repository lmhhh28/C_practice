#include <stdio.h>
#include <string.h>

int main()
{
    char s[80],element;
    int ret = 0,count = 0;
    scanf("%c\n%[^\n]",&element,s);
    
    while(s[count] != '\0')
    {
        count ++;
    }
    for(int i = count;i > 0;i --)
    {
        if(s[i - 1] == element)
        {
            printf("index = %d\n",i - 1);
            ret = 1;
            break;
        }
    }
    if(ret == 0)
    {
        printf("Not Found\n");
    }
}