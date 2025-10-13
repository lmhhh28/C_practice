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
    Node node; Element num;
    Position p = list->head;
    for(int i = 0; i < n; ++i) {
        node = (Node)malloc(sizeof(struct NodeList));
        scanf("%d", &num);
        node->data = num;
        node->next = NULL;
        p->next = node;
        p = p->next;
        ++list->len;
    }
}

void PrintfList(List list) {
    Position p = list->head->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, num, flag = 0, cnt = 1; scanf("%d", &n);
    List list = InitList();
    WriteList(list, n);
    scanf("%d", &num);
    Position p = list->head->next;
    while(p) {
        if(p->data == num) {
            flag = 1;
            break;
        }
        ++cnt;
        p = p->next;
    }
    if(flag) {
        printf("%d", p->data);
    } else {
        printf("%d 未找到。\n", num);
    }
    return 0;
}