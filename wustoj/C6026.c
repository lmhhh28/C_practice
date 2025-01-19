#include <stdio.h>
#include <string.h>

int main() {
    char input_string[101];
    fgets(input_string, 101, stdin);

    size_t len = strlen(input_string);
    if (input_string[len - 1] == '\n') {
        input_string[len - 1] = '\0';
        len--;
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", input_string[i]);
    }

    printf("\n");
    return 0;
}
