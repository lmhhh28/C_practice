#include <stdio.h>

typedef struct point
    {
        int Suneet[2];
        int Slavic[2];
    }point;

int Win_num(point *group);

int main()
{
    
    int num;scanf("%d",&num);
    point group[num];
    for(int i = 0;i < num;i ++)
    {
        scanf("%d %d %d %d",&group[i].Suneet[0],&group[i].Suneet[1],&group[i].Slavic[0],&group[i].Slavic[1]);
    }
    for(int i = 0;i < num;i ++)
    {
        printf("%d\n",Win_num(&group[i]));
    }
}


int Win_num(point *group)
{
    int WIN = 0;
    if((group -> Suneet[0] > group -> Slavic[0] && group -> Suneet[1] >= group -> Slavic[1]) || (group -> Suneet[0] == group -> Slavic[0] && group -> Suneet[1] > group -> Slavic[1]))
    {
        WIN += 2;
    }
    if((group -> Suneet[0] > group -> Slavic[1] && group -> Suneet[1] >= group -> Slavic[0]) || (group -> Suneet[0] == group -> Slavic[1] && group -> Suneet[1] > group -> Slavic[0]))
    {
        WIN += 2;
    }
    return WIN;
}