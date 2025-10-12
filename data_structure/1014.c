#include <stdio.h>
#include <stdlib.h>

typedef int Element;
struct NodeList {
    Element data;
    struct NodeList* next;
};
typedef struct NodeList *Node;
typedef Node Position;
typedef struct HeadList {
    int len;
    Node head;
} *List;

List InitList() {
    List list = (List)malloc(sizeof(struct HeadList));
    list->head = (Node)malloc(sizeof(struct NodeList));
    list->len = 0;
    list->head->next = NULL;
    return list;
}

void WriteList(List list, int n) {
    Element num; Node node;
    Position p = list->head;
    for(int i = 0; i < n; ++i) {
        node = (Node)malloc(sizeof(struct NodeList));
        scanf("%d", &num);
        node->data = num;
        node->next = p->next;
        p->next = node;
        ++list->len;
    }
}

void PrintList(List list) {
    Position p = list->head->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, pos;
    scanf("%d", &n);
    List list = InitList();
    WriteList(list, n);
    scanf("%d", &pos);
    if(pos > 0 && pos <= n) {
        Position p = list->head;
        for(int i = 0; i < pos; ++i) {
            p = p->next;
        }
        printf("%d\n", p->data);
    } else {
        printf("-1\n");
    }
    return 0;
}