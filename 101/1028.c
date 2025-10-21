#include <stdio.h>
#include <stdlib.h>

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

int push(Stack stack, int n) {
    if(stack->top == stack->cap) {
        return 0;
    } else {
        stack->arr[stack->top] = n;
        ++stack->top;
        return 1;
    }
}

int pop(Stack stack, int* num) {
    if(!stack->top) {
        return 0;
    } else {
        --stack->top;
        *num = stack->arr[stack->top];
        return 1;
    }
}

int empty(Stack stack) {
    return !stack->top ? 0 : 1;
}

void Submit() {
    Stack op = InitStack(1024), number = InitStack(1024);
    char buffer[10];
    int flag = 1;
    while(scanf("%s", buffer) == 1) {
        int num, state = sscanf(buffer, "%d", &num);
        if(state) {
            push(number, num);
        } else {
            char c = buffer[0];
            if(c == '+') {
                push(op, 1);
            }
            else if(c == '-') {
                push(op, 2);
            }
            else if(c == '*') {
                push(op, 3);
            }
            else if(c == '/') {
                push(op, 4);
            }
            else if(c == '%') {
                push(op, 5);
            }
        }
        if(op->top == 1) {
            int a, b;
            int c;
            if(pop(number, &b) && pop(number, &a)) {
                if(!pop(op, &c)) {
                    printf("错误：表达式不规范。\n1000000000\n");
                    flag = 0;
                    break;
                }
            } else {
                printf("错误：表达式不规范。\n1000000000\n");
                flag = 0;
                break;
            }
            if(c == 1) {
                push(number, a+b);
            }
            else if(c == 2) {
                push(number, a-b);
            }
            else if(c == 3) {
                push(number, a*b);
            }
            else if(c == 4) {
                if(!b) {
                    printf("错误：除法操作分母为零。\n1000000000\n");
                    flag = 0;
                    break;
                }
                push(number, a/b);
            }
            else if(c == 5) {
                if(!b) {
                    printf("错误：取模操作除数为零。\n1000000000\n");
                    flag = 0;
                    break;
                }
                push(number, a%b);
            }
        }
    }
    if(flag) {
        if(number->top != 1) {
            printf("错误：表达式不规范。\n1000000000\n");
            flag = 0;
        }
    }
    if(flag) {
        printf("%d\n", number->arr[number->bottom]);
    }
}

void test() {
    int nums[100], n = 0;
    char chars[100], c = 0;
    char word[100];
    
    printf("输入:\n");
    while (scanf("%s", word) == 1) {
        int num;
        sscanf(word, "%d", &num) == 1 ? (nums[n++] = num) : (chars[c++] = word[0]);
    }
    for(int i = 0; i < n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    for(int i = 0; i < c; ++i) {
        printf("%c ", chars[i]);
    }
}

int main() {
    // test();
    Submit();
    return 0;
}