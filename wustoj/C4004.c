#include <stdio.h>

int main()
{
    int grade;
    char a;
    scanf("%d",&grade);
    if(grade >= 90 && grade <= 100)
    {
        a = 'A';
    }
    else if(grade >= 80 && grade < 90)
    {
        a = 'B';
    }
    else if(grade >= 70 && grade < 80)
    {
        a = 'C';
    }
    else if(grade >= 60 && grade <70)
    {
        a = 'D';
    }
    else if(grade < 60)
    {
        a = 'E';
    }
    printf("score=%d,grade:%c\n",grade,a);
}