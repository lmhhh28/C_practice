#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double prices[n], total = 0.0;
    int quantities[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%lf", &prices[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &quantities[i]);
    }
    
    for (int i = 0; i < n; i++) {
        total += prices[i] * quantities[i];
    }
    
    printf("%.2f\n", total);
    
    return 0;
}
