#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    double pi = 0.0;

    for (int i = 1; i <= n; i++)
    {   
        pi += 4 / (4.0 * i - 3);
        pi -= 4 / (4.0 * i - 1);
    }
    printf("%lf\n", pi);
}