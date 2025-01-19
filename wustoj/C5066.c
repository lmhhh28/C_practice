#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);

    if (year < 2001) {
        printf("Invalid year!\n");
        return 0;
    }

    int found_leap_year = 0;

    for (int i = 2001; i <= year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            printf("%d\n", i);
            found_leap_year = 1;
        }
    }

    if (!found_leap_year) {
        printf("None\n");
    }

    return 0;
}
