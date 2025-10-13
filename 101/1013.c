#include <stdio.h>
#include <stdlib.h>

typedef int Element;
struct NodeList {
    Element data;
    struct NodeList* next;
};
typedef struct NodeList NodeList;
typedef NodeList *Position; 
typedef Position Node;
typedef struct HeadList {
    int len;
    Node head;
}*List;

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
        node->next = NULL;
        p->next = node;
        p = p->next;
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
    int n;
    scanf("%d", &n);
    List list = InitList();
    WriteList(list, n);
    printf("%d\n", list->len);
    return 0;
}



