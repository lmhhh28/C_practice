#include <stdio.h>

long long gcd(int a,int b);

int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",gcd(a,b));
}

long long gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}