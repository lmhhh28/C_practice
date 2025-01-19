#include <stdio.h>

int main()
{
    long long n,k,count;
    scanf("%lld",&count);
    for(int i = 0;i < count;i ++){
        scanf("%lld %lld",&n,&k);
        printf("%lld\n",n == 1 ? 0 : (n < k ? 1 : (n - k) / (k - 1) + 1 + (((n - k) % (k - 1)) || 0)));
    }
}