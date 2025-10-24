#include <stdio.h>
#include <stdlib.h>
#define MAX 200
 
char match[MAX];            
int top = -1, flag = 0;     

void IfMatch(char left, char right)
{   
    if (top == -1)                
    {
        if (right == '>') printf("NO\n?-*/");    
        else printf("NO\n?-%c", right);           
        exit(0);                               
    }
    else if (match[top] == left) --top;           
    else                                       
    {
        if (match[top] == '<')
            printf("NO\n/*-?");
        else printf("NO\n%c-?", match[top]);
        exit(0);
    }
}
 
int main()
{
    char str[MAX];
    while (scanf("%s", str) != EOF && str[0] != '.')
    {
        for (int i = 0; i < strlen(str); ++i)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                match[++top] = str[i];                   
            else if (str[i] == '/' && str[i + 1] == '*') 
            {
                match[++top] = '<';
                ++i;
            }
            else if (str[i] == ')') IfMatch('(', str[i]);
            else if (str[i] == ']') IfMatch('[', str[i]);
            else if (str[i] == '}') IfMatch('{', str[i]);
            else if (str[i] == '*' && str[i + 1] == '/')
            {
                IfMatch('<', '>');
                ++i;
            }
        }
    }
 
    if (top == -1) printf("YES");
    else printf("NO\n%c-?", match[top]);
 
    return 0;

}