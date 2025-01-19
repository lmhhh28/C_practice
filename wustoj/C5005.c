#include <stdio.h>
#include <math.h>

//double sum(double n);

int main()
{
    double n,sum;
    scanf("%lf",&n);
    for(int i = 1;i <= n;i ++)
    {
        sum = sum + (pow((1 + sqrt(5)) / 2,i + 2) - pow((1 - sqrt(5)) / 2,i + 2)) / (pow((1 + sqrt(5)) / 2,i + 1) - pow((1 - sqrt(5)) / 2,i + 1));
    }
    printf("%lf\n",sum);
}



/*double sum(double n)
{
    if(n == 1)
    {
        return 2;
    }
    else if(n == 2)
    {
        return 3.5;
    }
    else
    {
        return sum(n - 1) + 1 / (sum(n - 1) - sum(n - 2)) + 1; 
    }
}*/