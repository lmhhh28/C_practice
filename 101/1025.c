#include <stdio.h>
#include <string.h>

typedef struct Stack {
    int cap, bottom, top;
    int* arr;
} *Stack;

Stack InitStack(int cap) {
    Stack stack = (Stack)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->bottom = 0; stack->top = 0;
    stack->arr = (int*)malloc(cap*sizeof(int));
    return stack;
}

int pop(Stack stack) {
    if(stack->top == stack->bottom) {
        return 0x80000000;
    } else {
        int num = stack->arr[stack->top-1];
        --stack->top;
        return num;  
    }
}

int push(Stack stack, int num) {
    if(stack->top - stack->bottom == stack->cap) {
        return 0;
    } else {
        stack->arr[stack->top] = num;
        ++stack->top;
        return 1;
    }
}

int main() {
    int n; scanf("%d", &n);
    Stack stack = InitStack(n);
    int len = 0;
    while(1) {
        int num;
        scanf("%d", &num);
        int state = push(stack, num);
        if(state) {
            ++len;
        } else {
            printf("错误：栈已满。\n");
            break;
        }
        if(len == n) {
            break;
        }
    }
    while(1) {
        int num = pop(stack);
        if(num != 0x80000000) {
            printf("%d\n", num);
        } else {
            printf("错误：栈为空。\n-1\n错误：栈为空。\n");
            break;
        }
    }
    return 0;
}