#include <stdio.h>

int main()
{
    typedef struct Vector
    {
        double x;
        double y;
    }Vector;
    Vector v_1,v_2;
    scanf("%lf %lf %lf %lf",&v_1.x,&v_1.y,&v_2.x,&v_2.y);
    printf("(%.1lf,%.1lf)\n",v_1.x + v_2.x,v_1.y + v_2.y);
}