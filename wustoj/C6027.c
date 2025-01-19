#include <stdio.h>

void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char str[101];
    char copy[101];

    
    fgets(str, sizeof(str), stdin);

    my_strcpy(copy, str);

    printf("%s\n", copy);
    
    return 0;
}
