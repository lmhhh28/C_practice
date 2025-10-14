#include <stdio.h>

int fac(int n) {
    return n == 0 ? 1 : n*fac(n-1); 
}

int main() {
    int n; scanf("%d", &n);
    printf("%d\n", fac(n));
}