#include <stdio.h>

int main() {
    int num;
    int index = 0;
    int found = 0;
    while (scanf("%d", &num) != EOF) {
        index++;
        if (num == 250) {
            printf("%d\n", index);
            found = 1;
            break;
        }
    }

    return 0;
}
