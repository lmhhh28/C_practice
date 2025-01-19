#include <stdio.h>

int main()
{
    char N;char s[4];
    scanf("%c",&N);
    for(int i = 0;i < 4;i ++)
    {
        s[i] = N + i;
    }
 
    if(N != '0')
    {
        printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n",s[0],s[1],s[2],s[0],s[1],s[3],s[0],s[2],s[1],s[0],s[2],s[3],s[0],s[3],s[1],s[0],s[3],s[2],s[1],s[0],s[2],s[1],s[0],s[3],s[1],s[2],s[0],s[1],s[2],s[3],s[1],s[3],s[0],s[1],s[3],s[2],s[2],s[0],s[1],s[2],s[0],s[3],s[2],s[1],s[0],s[2],s[1],s[3],s[2],s[3],s[0],s[2],s[3],s[1],s[3],s[0],s[1],s[3],s[0],s[2],s[3],s[1],s[0],s[3],s[1],s[2],s[3],s[2],s[0],s[3],s[2],s[1]);
    }
    else
    {
        printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n",s[1],s[0],s[2],s[1],s[0],s[3],s[1],s[2],s[0],s[1],s[2],s[3],s[1],s[3],s[0],s[1],s[3],s[2],s[2],s[0],s[1],s[2],s[0],s[3],s[2],s[1],s[0],s[2],s[1],s[3],s[2],s[3],s[0],s[2],s[3],s[1],s[3],s[0],s[1],s[3],s[0],s[2],s[3],s[1],s[0],s[3],s[1],s[2],s[3],s[2],s[0],s[3],s[2],s[1]);
    }
    
}
