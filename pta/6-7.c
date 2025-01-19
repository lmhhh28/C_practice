#include <stdio.h>
#define MAXS 80

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    scanf("%s",s);
    StringCount(s);

    return 0;
}

void StringCount( char s[] )
{
    int letter = 0,blank = 0,digit = 0,other = 0;
    while(*s != '\0')
    {
        if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
        {
            letter ++;
        }
        else if(*s == ' ' || *s == '\n')
        {
            blank ++;
        }
        else if(*s >= '0' && *s <= '9')
        {
            digit ++;
        }
        else
        {
            other ++;
        }
        s ++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n",letter,blank,digit,other);
}
