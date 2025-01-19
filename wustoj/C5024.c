#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char gender;
        double height, ideal_height;
        scanf(" %c %lf", &gender, &height);
        
        if (gender == 'F') {
            ideal_height = height * 1.09;
        } else if (gender == 'M') {
            ideal_height = height / 1.09;
        }
        
        printf("%.2lf\n", ideal_height);
    }

    return 0;
}