#include <stdio.h>
#include <time.h>

int main() {
    char d1[11], d2[11];
    scanf("%s %s", d1, d2);

    struct tm date1 = {0}, date2 = {0};
    sscanf(d1, "%d-%d-%d", &date1.tm_year, &date1.tm_mon, &date1.tm_mday);
    date1.tm_year -= 1900;
    date1.tm_mon -= 1;

    sscanf(d2, "%d-%d-%d", &date2.tm_year, &date2.tm_mon, &date2.tm_mday);
    date2.tm_year -= 1900;
    date2.tm_mon -= 1;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    double seconds = difftime(time2, time1);
    int days = seconds / (60 * 60 * 24);

    printf("%d\n", days);
    return 0;
}
