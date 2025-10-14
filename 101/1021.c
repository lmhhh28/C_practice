#include <stdio.h>
#include <stdlib.h>

typedef int Element;
struct NodeList {
    Element data;
    struct NodeList* next;
};
typedef struct NodeList* Node;
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
    Position p = list->head;
    Node node; Element num;
    for(int i = 0; i < n; ++i) {
        node = (Node)malloc(sizeof(struct NodeList));
        scanf("%d", &num);
        node->data = num;
        node->next = NULL;
        p->next = node;
        p = p->next;
        ++(list->len);
    }
    p->next = list->head->next;
}

void PrintList(List list, int n) {
    Position p = list->head->next;
    int len = list->len;
    n = n % len;
    for(int i = 0; i < len - n; ++i) {
        p = p->next;
    }
    int flag = 0;
    for(int i = 0; i < len; ++i) {
        if(!flag) {
            printf("%d", p->data);
            flag = 1;
        } else {
            printf(" %d", p->data);
        }
        p = p->next;
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    List list = InitList();
    WriteList(list, n);
    PrintList(list, m);
    return 0;
}

// int main() {
//     int n, m, num; scanf("%d%d", &n, &m);
//     int *arr = (int*)malloc(n*sizeof(int));
//     for(int i = 0; i < n; ++i) {
//         scanf("%d", &num);
//         arr[i] = num;
//     }
//     int flag = 0;
//     m = m % n;
//     for(int i = n - m, cnt = 0; cnt < n ; ++i, ++cnt) {
//         if(i == n) {
//             i = 0;
//         }
//         if(!flag) {
//             printf("%d", arr[i]);
//             flag = 1;
//         } else {
//             printf(" %d", arr[i]);
//         }
//     }
//     return 0;
// }