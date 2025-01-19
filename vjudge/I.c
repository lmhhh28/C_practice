#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[11];
        scanf("%s", s);

        int len = strlen(s);
        bool all_same = true;

        for (int i = 1; i < len; i++) {
            if (s[i] != s[0]) {
                all_same = false;
                break;
            }
        }

        if (all_same) {
            printf("NO\n");
        } else {
            printf("YES\n");
            printf("%c", s[len - 1]);
            for (int i = 0; i < len - 1; i++)
                printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}
