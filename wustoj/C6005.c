#include <stdio.h>

int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

int main() {
    int n, x, result;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    result = binary_search(arr, n, x);

    if (result != -1)
        printf("%d\n", result);
    else
        printf("Not found\n");
    
    return 0;
}

