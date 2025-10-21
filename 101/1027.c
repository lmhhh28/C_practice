#include <stdio.h>
#include <stdlib.h>

typedef struct NodeList {
    int data;
    struct NodeList* next;
} *Node;
typedef Node Position;
typedef struct Que {
    int len;
    Node head, tail;
} *Que;

Que InitQue() {
    Que que = (Que)malloc(sizeof(struct Que));
    que->len = 0;
    que->head = (Node)malloc(sizeof(struct NodeList));
    que->head->next = NULL;
    que->tail = que->head;
    return que;
}

void InQue(Que que, int num) {
    Node node = (Node)malloc(sizeof(struct NodeList));
    node->data = num;
    node->next = NULL;
    que->tail->next = node;
    que->tail = que->tail->next;
    ++que->len;
}

int DeQue(Que que) {
    if(!que->len) {
        return -1;
    } else {
        Node temp = que->head->next;
        int num = temp->data;
        que->head->next = temp->next;
        free(temp);
        --que->len;
        return num;
    }
}

void Submit() {
    int n, num; scanf("%d", &n);
    Que que = InitQue();
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        InQue(que, num);
    }
    while(1) {
        int state = DeQue(que);
        if(state == -1) {
            printf("错误：队列为空。\n-1\n错误：队列为空。\n");
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