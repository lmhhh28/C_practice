#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n,i = 1;
    scanf("%d",&n);
    while(i <= n)
    {
        int j = 0;
        while(j < 5 && i <= n)
        {
            printf("%10d",fibonacci(i ++));
            j ++;
        }
        printf("\n");
    }
            
}

int fibonacci(int n)
{
    int n1 = 0,n2 = 1,n3 = n;
	int i = 0;
	for(i = 2;i <= n;i ++)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

