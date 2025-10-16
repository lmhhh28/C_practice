#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct NodeList {
    Element a, b;
    struct NodeList* next;
} *Node;
typedef Node Position;
typedef struct HeadList {
    int len;
    Node head;
} *List;

List InitList() {
    List list = (List)malloc(sizeof(struct HeadList));
    list->head = (Node)malloc(sizeof(struct NodeList));
    Node node = (Node)malloc(sizeof(struct NodeList));
    node->next = NULL;
    node->a = -1; node->b = 0x80000000;
    list->len = 0;
    list->head->next = node;
    list->head->b = 0x7fffffff;
    return list;
}

void WriteList(List list, int n) {
    Node node; Position p = list->head;
    for(int i = 0; i < n; ++i) {
        node = (Node)malloc(sizeof(struct NodeList));
        scanf("%d%d", &(node->a), &(node->b));
        node->next = p->next;
        p->next = node;
        p = p->next;
    }
    list->len = n;
}

void PrintList(List list) {
    Position p = list->head->next;
    int flag = 0;
    if(!list->len) {
        printf("0 0");
    } else {
        while(p->b != 0x80000000) {
            if(!flag) {
                if(p->a) {
                    printf("%d %d", p->a, p->b);
                    flag = 1;
                }
            } else {
                if(p->a) {
                    printf(" %d %d", p->a, p->b);
                }
            }
            p = p->next;
        }
    }
}

void Insert(List list, Node node) {
    Position p = list->head;
    node->next = NULL; 
    int flag = 0;
    while(p->next) {
        if(node->b < p->b && node->b > p->next->b) {
            node->next = p->next;
            p->next = node;
            ++list->len;
            break;
        } else if(node->b == p->b) {
            p->a += node->a;
            free(node);
            break;
        }
        p = p->next;
    }
}

int main() {
    int n1, n2;
    List a = InitList(), b = InitList(), res = InitList();
    scanf("%d", &n1);
    WriteList(a, n1);
    scanf("%d", &n2);
    WriteList(b, n2);
    Position p = a->head->next, q = b->head->next;
    for(int i = 0; i < b->len; ++i) {
        for(int j = 0; j < a->len; ++j) {
            Node node = (Node)malloc(sizeof(struct NodeList));
            node->next = NULL; node->a = (p->a)*(q->a);
            node->b = (p->b) + (q->b);
            Insert(res, node);
            p = p->next;
        }
        p = a->head->next;
        q = q->next;
    }
    PrintList(res);
    return 0;
}