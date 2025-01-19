#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d",&N);
    printf("%d\n",(int)(3 * pow(2,N - 1) - 2));
}