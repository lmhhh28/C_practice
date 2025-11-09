#include <stdio.h>
int main() {
    int a, b;
    char c;
    scanf("%d%d %c", &a, &b, &c);
    printf("(%d)%c(%d)", a, c, b);
}