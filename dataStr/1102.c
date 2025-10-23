#include <stdio.h>

#define MAXN 20

int Delete( int A[], int L, int minA, int maxA );

int main()
{
    int A[MAXN], L, minA, maxA, i;

    scanf("%d", &L);
    for (i=0; i<L; i++) scanf("%d", &A[i]);
    scanf("%d %d", &minA, &maxA);
    L = Delete(A, L, minA, maxA);
    for (i=0; i<L; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

int Delete( int A[], int L, int minA, int maxA ) {
    int k = 0;
    for (int i = 0; i < L; i++) {
        if (A[i] <= minA || A[i] >= maxA) {
            A[k] = A[i];
            k++;
        }
    }
    return k;
}
