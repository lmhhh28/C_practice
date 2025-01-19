#include <stdio.h>

int main() {
    int score;
    
    
    scanf("%d", &score);
    
    
    if (score > 85) {
        printf("very good\n");
    } else if (score >= 60 && score <= 85) {
        printf("good\n");
    } else {
        printf("no good\n");
    }
    return 0;
}
