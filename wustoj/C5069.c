#include <stdio.h>
#include <time.h>

int main() {
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    
    struct tm birth_date = {0};
    birth_date.tm_year = year - 1900;
    birth_date.tm_mon = month - 1;
    birth_date.tm_mday = day;
    
    time_t birth_time = mktime(&birth_date);
    
    const int days_to_add = 10000;
    time_t future_time = birth_time + days_to_add * 24 * 60 * 60;
    
    struct tm *future_date = localtime(&future_time);
    
    printf("%d-%d-%d\n", future_date->tm_year + 1900, future_date->tm_mon + 1, future_date->tm_mday);
    
    return 0;
}
