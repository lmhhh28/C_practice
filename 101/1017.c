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

void Insert(List list, int n, Element num) {
    Position p = list->head;
    for(int i = 1; i < n; ++i) {
        p = p->next;
    }
    Node node = (Node)malloc(sizeof(struct NodeList));
    node->data = num;
    node->next = p->next;
    p->next = node;
    ++list->len;
}

void Delete(List list, int n) {
    Position p = list->head;
    for(int i = 1; i < n; ++i) {
        p = p->next;
    }
    Position temp = p->next;
    p->next = p->next->next;
    --list->len;
    free(temp);
}

void PrintList(List list) {
    Position p = list->head->next;
    while(p) {
        printf(" %d", p->data);
        p = p->next;
    }
}

int main() {
    int n, num, pos; scanf("%d", &n);
    List list = InitList();
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        Insert(list, 1, num);
    }
    scanf("%d", &pos);
    if(pos > 0 && pos <= n) {
        Delete(list, pos);
    } else {
        printf("错误：删除位置不合法。\n");
    }
    printf("%d:", list->len);
    PrintList(list);
    return 0;
}

