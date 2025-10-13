#include <stdio.h>
#include <stdlib.h>

typedef int Element;
struct NodeList {
    Element val, pow;
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
    Node node; Element val, pow;
    Position p = list->head;
    for(int i = 0; i < n; ++i) {
        node = (Node)malloc(sizeof(struct NodeList));
        scanf("%d %d", &val, &pow);
        node->val = val; node->pow = pow;
        node->next = NULL;
        p->next = node;
        p = p->next;
        ++list->len;
    }
}

void push_back(List list, Node node) {
    Position p = list->head;
    while(p->next) {
        p = p->next;
    }
    p->next = node;
    node->next = NULL;
    ++list->len;
}

Node Cut(List list, int n) {
    Position p = list->head;
    for(int i = 1; i < n; ++i) {
        p = p->next;
    }
    Position node = p->next;
    p->next = node->next;
    node->next = NULL;
    --list->len;
    return node;
}

void PrintList(List list) {
    Position p = list->head->next;
    while(p) {
        if(p->val) {
            printf("%.2lf %d\n", (double)p->val, p->pow);
        }
        p = p->next;
    }
}

int main() {
    int n1, n2;
    List list1=InitList(), list2=InitList(), res = InitList();
    scanf("%d", &n1);
    WriteList(list1, n1);
    scanf("%d", &n2);
    WriteList(list2, n2);
    Position p1 = list1->head->next, p2 = list2->head->next;
    while(p1 && p2) {
        if(p1->pow > p2->pow) {
            push_back(res, Cut(list1, 1));
        } else if(p1->pow == p2->pow) {
            p1->val += p2->val;
            if(!p1->val) {
                free(Cut(list1, 1)); free(Cut(list2, 1)); 
            } else {
                push_back(res, Cut(list1, 1));
                free(Cut(list2, 1));
            }
        } else {
            push_back(res, Cut(list2, 1));
        }
        p1 = list1->head->next; p2 = list2->head->next;
    }
    Position p = res->head;
    while(p->next) {
        p = p->next;
    }
    if(p1) {
        p->next = p1;
    } else if(p2) {
        p->next = p2;
    }
    PrintList(res);
    return 0;
}