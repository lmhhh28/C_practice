#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100],str2[100];
    getw(str1);
    getw(str2);
    int count = 0;
    while(str1[count] == str2[count])
    {
        if(str1[count] == '\0')
        {
            break;
        }
        else
        {
            count ++;
        }
    }
    printf("%d\n",str1[count] - str2[count]);
}