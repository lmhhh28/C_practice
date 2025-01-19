#include <stdio.h>

void sort_array(int arr[], int n) {
    int odd[n], even[n], odd_count = 0, even_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd[odd_count++] = arr[i];
        } else {
            even[even_count++] = arr[i];
        }
    }

    for (int i = 0; i < odd_count - 1; i++) {
        for (int j = i + 1; j < odd_count; j++) {
            if (odd[i] > odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    for (int i = 0; i < even_count - 1; i++) {
        for (int j = i + 1; j < even_count; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    int first = 1;
    for (int i = 0; i < odd_count; i++) {
        if (first) {
            printf("%d", odd[i]);
            first = 0;
        } else {
            printf(" %d", odd[i]);
        }
    }
    for (int i = 0; i < even_count; i++) {
        printf(" %d", even[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort_array(arr, n);
    return 0;
}
