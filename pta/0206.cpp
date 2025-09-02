#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int hour, min;
    scanf("%d:%d", &hour, &min);
    printf("%d:%d ", hour == 12 ? 12 : hour % 12, min);
    if(hour >= 12 && hour < 24) {
        printf("PM\n");
    } else {
        printf("AM\n");
    }
    return 0;
}