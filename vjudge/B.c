#include <stdio.h>
#define LENTH 2000

typedef struct string
{
    char input[LENTH];
    char aim[LENTH];
}string;

int Get_lenth(char *p);
int Compare(string *str);

int main()
{
    int num;scanf("%d",&num);
    string str[num];
    for(int i = 0;i < num;i ++)
    {
        scanf("%s",str[i].aim);
        scanf("%s",str[i].input);
    }
    for(int i = 0;i < num;i ++)
    {
        if(Compare(&str[i]) == 1)
        {
            for(int j = 0;j < Get_lenth(str -> aim);j ++)
            {
                if(str[i].aim[j] == '?')
                {
                    str[i].aim[j] = 'a';
                    //printf("%c\n",str[i].aim[j]);
                }
            }
            printf("YES\n%s\n",str[i].aim);
        }
        else
        {
            printf("NO\n");
        }
    }
}

int Get_lenth(char *p)
{
    int count = 0;
    for(;*(p + count) != '\0';count ++);
    return count;
}

int Compare(string *str)
{
    int input_lenth = Get_lenth(str -> input),aim_lenth = Get_lenth(str -> aim),ret = 1;
    for(int i = 0,j = 0;i < input_lenth;i ++)
    {   
        int count = 0;
        for(;j <= aim_lenth - input_lenth + i;j ++)
        {
            if(str -> input[i] == str -> aim[j])
            {
                j ++;count ++;
                break;
            }
            if(str -> aim[j] == '?')
            {
                str -> aim[j] = str -> input[i];
                j ++;count ++;
                break;
            }
        }
        if(count == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}