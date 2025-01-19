#include <stdio.h>
#include <string.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int product = A * B;

    char product_str[20];
    sprintf(product_str, "%d", product);

    int len = strlen(product_str);
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(product_str[i]);
    }
    putchar('\n');

    return 0;
}
