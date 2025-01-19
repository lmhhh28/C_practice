#include <stdio.h>

int main() {
    int N, NA, NB;
    scanf("%d %d %d", &N, &NA, &NB);
    
    int a[NA], b[NB];
    for (int i = 0; i < NA; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < NB; i++) {
        scanf("%d", &b[i]);
    }

    int a_wins = 0, b_wins = 0;

    for (int i = 0; i < N; i++) {
        int a_choice = a[i % NA];
        int b_choice = b[i % NB];

        if (a_choice == b_choice) {
            continue;
        }
        
        if ((a_choice == 0 && b_choice == 2) || 
            (a_choice == 2 && b_choice == 5) || 
            (a_choice == 5 && b_choice == 0)) {
            a_wins++;
        } else {
            b_wins++;
        }
    }

    if (a_wins > b_wins) {
        printf("A\n");
    } else if (b_wins > a_wins) {
        printf("B\n");
    } else {
        printf("draw\n");
    }

    return 0;
}
