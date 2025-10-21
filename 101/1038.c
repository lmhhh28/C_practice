#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int) * capacity);
    dq->front = 0;
    dq->rear = -1;
    dq->capacity = capacity;
    return dq;
}

int isEmpty(Deque *dq) {
    return dq->front > dq->rear;
}

int getFront(Deque *dq) {
    return dq->data[dq->front];
}

int getRear(Deque *dq) {
    return dq->data[dq->rear];
}

void popFront(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->front++;
    }
}

void popRear(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->rear--;
    }
}

void pushRear(Deque *dq, int value) {
    dq->data[++dq->rear] = value;
}

void freeDeque(Deque *dq) {
    free(dq->data);
    free(dq);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *nums = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    Deque *dq = createDeque(n);
    int *result = (int*)malloc(sizeof(int) * (n - k + 1));
    int resultIndex = 0;
    for (int i = 0; i < n; i++) {
        if (!isEmpty(dq) && getFront(dq) <= i - k) {
            popFront(dq);
        }
        while (!isEmpty(dq) && nums[i] >= nums[getRear(dq)]) {
            popRear(dq);
        }
        pushRear(dq, i);
        if (i >= k - 1) {
            result[resultIndex++] = nums[getFront(dq)];
        }
    }
    for (int i = 0; i < resultIndex; i++) {
        printf("%d", result[i]);
        if (i < resultIndex - 1) {
            printf(" ");
        }
    }
    printf("\n");
    free(nums);
    free(result);
    freeDeque(dq);
    
    return 0;
}
