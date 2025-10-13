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
    list->len = 0;
    list->head = (Node)malloc(sizeof(struct NodeList));
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

void PrintList(List list) {
    Position p = list->head->next;
    while(p) {
        printf(" %d", p->data);
        p = p->next;
    }
}

int main() {
    int n; scanf("%d", &n);
    List list = InitList();
    WriteList(list, n);
    printf("%d:", list->len);
    PrintList(list);
    printf("\n错误：插入位置不合法。\n错误：插入位置不合法。");
    return 0;
}