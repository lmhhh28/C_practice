#include <stdio.h>

int main()
{
    char s[80];
    int count = 0,count_ = 0;
    scanf("%[^\n]",s);
    while(s[count] != '\0')
    {
        count ++;
    }
    for(int i = 0;i < count;i ++)
    {
        if(s[i] > 'A' && s[i] <= 'Z' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
        {
            count_ ++;
        }
    }
    printf("%d\n",count_);
}