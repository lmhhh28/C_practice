#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_A 1000000000

bool is_valid(long long x, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (x % arr[i] == 0 || arr[i] % x == 0) {
            return false;
        }
    }
    return true;
}

long long find_valid_x(int *arr, int n, int max_a) {
    long long candidate = (long long)max_a + 1;
    while (!is_valid(candidate, arr, n)) {
        candidate++;
        if (candidate > 1000000000000000000LL) {
            return -1; 
        }
    }

    return candidate;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        bool contains_one = false;
        int max_a = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] == 1) {
                contains_one = true;
            }
            if (arr[i] > max_a) {
                max_a = arr[i];
            }
        }

        if (contains_one) {
            printf("-1\n");
        } else {
            long long result = find_valid_x(arr, n, max_a);
            printf("%lld\n", result);
        }

        free(arr);
    }

    return 0;
}

