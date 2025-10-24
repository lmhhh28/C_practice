#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int cap, bottom, top;
    int* arr;
} *Stack;

Stack InitStack(int cap) {
    Stack stack = (Stack)malloc(sizeof(struct stack));
    stack->cap = cap;
    stack->bottom = stack->top = 0;
    stack->arr = (int*)malloc(cap*sizeof(int));
    return stack;
}



int IsEmpty(Stack stack) {
    return stack->bottom == stack->top ? 1 : 0;
}

int IsFull(Stack stack) {
    return stack->top == stack->cap ? 1 : 0;
}

int get_top(Stack stack, int* num) {
    if(IsEmpty(stack)) {
        return 0;
    }
    *num = stack->arr[stack->top - 1];
    return 1;
}

int push(Stack stack, int num) {
    if(IsFull(stack)) {
        return 0;
    }
    stack->arr[stack->top++] = num;
    return 1;
}

int pop(Stack stack, int* num) {
    int state = get_top(stack, num);
    if(!state) {
        return 0;
    }
    --stack->top;
    return 1;
}

void Submit() {
    int n;
    scanf("%d", &n);
    Stack stack1, stack2;
    stack1 = InitStack(1001); stack2 = InitStack(1001);
    for(int i = 0; i < n; ++i) {
        char c; scanf(" %c", &c);
        // printf("Input: %c YES\n", c);
        if(c == 'I') {
            int num;
            scanf("%d", &num);
            push(stack1, num);
        } else if(c == 'O') {
            int num, cnt = 0;
            if(!IsEmpty(stack2)) {
                pop(stack2, &num);
                ++cnt;
                printf("%d %d\n", num, cnt);
            } else {
                if(IsEmpty(stack1)) {
                    printf("ERROR\n");
                } else {
                    while(!IsEmpty(stack1)) {
                        pop(stack1, &num);
                        push(stack2, num);
                        cnt+=2;
                    }
                    pop(stack2, &num);
                    ++cnt;
                    printf("%d %d\n", num, cnt);
                }
            }
        }
    }
}

int main() {
    Submit();
    return 0;
}


