#include <stdio.h>
#include <stdlib.h>

typedef struct que {
    int cap, len, first, last;
    int* arr;
} *Que;

Que InitQue(int cap) {
    Que que = (Que)malloc(sizeof(struct que));
    que->len = 0; que->first = 0; que->last = 0; que->cap = cap;
    que->arr = (int*)malloc(cap*sizeof(int));
    return que;
}

int InQue(Que que, int num) {
    if(que->last == que->cap) {
        return 0;
    } else {
        que->arr[que->last] = num;
        ++que->last;
        ++que->len;
        return 1;
    } 
}

int DeQue(Que que) {
    if(que->first == que->last) {
        return -1;
    } else {
        int num = que->arr[que->first];
        ++que->first;
        --que->len;
        return num;
    }
}

void Submit() {
    int n; scanf("%d", &n);
    Que que = InitQue(n);
    int num;
    while(1) {
        scanf("%d", &num);
        int state = InQue(que, num);
        if(!state) {
            printf("错误：队列已满。\n");
            break;
        }
    }
    while(1) {
        int state = DeQue(que);
        if(state == -1) {
            printf("错误：队列为空。\n-1\n错误：队列为空。");
            break;
        } else {
            printf("%d\n", state);
        }
    }
}

int main() {
    Submit();
    return 0;
}