#include <stdio.h>

int is_A_type(int num);

int main()
{
    int N, count = 0;
    scanf("%d", &N);

    for (int i = 1; i < N; i++)
    {
        if (is_A_type(i))
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

int is_A_type(int num)
{
    int ones = 0, zeros = 0, total_bits = 0;
    
    while (num > 0)
    {
        if (num & 1)
        {
            ones++;
        }
        else
        {
            zeros++;
        }
        num >>= 1;
        total_bits++;
    }

    return ones > zeros;
}
