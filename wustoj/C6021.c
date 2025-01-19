#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101];  
    fgets(str, sizeof(str), stdin);  

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    printf("%s", str);  

    return 0;
}