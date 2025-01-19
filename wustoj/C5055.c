#include <stdio.h>
#include <ctype.h>

void letter_substitution_cipher(char* text) {
    while (*text) {
        if (islower(*text)) {
            if (*text == 'z') {
                putchar('A');
            } else {
                putchar(toupper(*text + 1));
            }
        } else if (isupper(*text)) {
            if (*text == 'Z') {
                putchar('a');
            } else {
                putchar(tolower(*text + 1));
            }
        } else {
            putchar(*text);
        }
        text++;
    }
}

int main() {
    char input[1000];
    
    fgets(input, sizeof(input), stdin);
    
    letter_substitution_cipher(input);
    
    return 0;
}
