#include <stdio.h>

int main()
{
    char s[80],s_[80];
    int count = 0;
    scanf("%[^\n]",s);
    while(s[count] != '\0')
    {
        count ++;
    }
    for(int i = 0;i < count;i ++)
    {
        s_[i] = s[count - 1 - i]; 
    }
    for(int i = 0;i < count;i ++)
    {
        printf("%c",s_[i]);
    }
}