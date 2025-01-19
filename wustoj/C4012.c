#include <stdio.h>

int main() {
    int N;

    
    scanf("%d", &N);

    
    int day_in_cycle = N % 5;

    if (day_in_cycle == 1 || day_in_cycle == 2 || day_in_cycle == 3) {
        printf("Fishing in day %d\n", N);
    } else {
        printf("Drying in day %d\n", N);
    }

    return 0;
}
