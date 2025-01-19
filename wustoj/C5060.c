#include <stdio.h>

int main() {
    int hh, mm;
    
    scanf("%d:%d", &hh, &mm);
    
    if (hh >= 0 && hh <= 12) {
        printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
    } else {
        int dang_count = (mm == 0) ? hh - 12 : hh - 11;
        
        for (int i = 0; i < dang_count; i++) {
            printf("Dang");
        }
        printf("\n");
    }

    return 0;
}