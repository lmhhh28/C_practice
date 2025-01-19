#include <stdio.h>

int main() {
    char input[1000];
    int count[26] = {0};
    
    fgets(input, sizeof(input), stdin);
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            count[input[i] - 'A']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        printf("%c(%d)", 'A' + i, count[i]);
        if (i % 5 == 4) {
            printf("\n");
        } else {
            printf("");
        }
    }
    
    return 0;
}