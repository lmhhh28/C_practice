#include <stdio.h>

int main()
{
    char s[1000];
    int count,i = 0,ret = 0,flag = 0;
    count = scanf("%[^\n]",s);
    if(count == 0)
    {
        printf("%d\n",0);
    }
    //printf("%s %d\n",s,count);
    else
    {
        while(*(s + i) != '\0')
        {
            count = 0;
            while(*(s + i) == ' ')
            {
                i ++;
            }
            if(*(s + i) == '\0')
            {
                if(ret == 0)
                {
                    printf("%d",0);
                }
                break;
            }
            while(*(s + i) != ' ' && *(s + i) != '\0')
            {
                count ++;
                i ++;
                ret = 1;
            }
            //printf("%d ",count);
            if(flag == 1)
            {
                printf(" %d",count);
            }
            else
            {
                printf("%d",count);
                flag = 1;
            }
        }
        printf("\n");
    }
}