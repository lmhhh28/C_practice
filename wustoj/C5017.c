#include <stdio.h>

int count(char *s);

int main()
{
    char s_[100];
    const char *s[] = 
    {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu",
        "fu",
    };
    
    scanf("%s",s_);
    int count_ = count(s_);
    for(int i = 0;i < count_;i ++)
    {
        for(int j = 0;j < 11;j ++)
        {
            if(s_[i] == '-')
            {
                printf("%s ",s[10]);
                break;
            }
            else if(s_[i] - 48 == j)
            {
                printf("%s ",s[j]);
                break;
            }
        }
    }
}

int count(char *s)
{
    int count = 0;
    while(s[count] != '\0')
    {
        count ++;
    }
    return count;
}