#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double height = 100.0;  
    double total_distance = 0.0;  

    
    for (int i = 1; i <= n; i++) {
        total_distance += height;  
        if (i != n) {
            total_distance += height / 2.0;  
        }
        height /= 2.0; 
    }

    
    printf("%lf %lf\n", total_distance, height);

    return 0;
}
