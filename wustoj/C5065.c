#include <stdio.h>

int is_palindrome(long long num) {
    long long reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

long long reverse_number(long long num) {
    long long reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    long long num;
    int count = 0;

    scanf("%lld", &num);
    printf("%lld", num);

    while (!is_palindrome(num)) {
        long long reversed = reverse_number(num);
        num += reversed;
        count++;
        printf("--->%lld", num);
    }

    printf("\n%d\n", count);

    return 0;
}
