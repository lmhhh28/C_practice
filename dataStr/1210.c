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

void Insert(List list, int n, int num) {
    Position p = list->head;
    for(int i = 1; i < n; ++i) {
        p = p->next;
    }
    Node node = (Node)malloc(sizeof(struct NodeList));
    node->data = num;
    node->next = p->next;
    p->next = node;
    ++(list->len);
}

void PrintList(List list) {
    Position p = list->head->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int n, pos, num; scanf("%d", &n);
    List list = InitList();
    WriteList(list, n);
    scanf("%d%d", &pos, &num);
    if(list->len == 10000) {
        printf("错误：表满不能插入。\n");
    }
    else if(pos < 1 || pos > list->len+1) {
        printf("错误：插入位置不合法。\n");
    } else {
        Insert(list, pos, num);
    }
    PrintList(list);
    return 0;
}