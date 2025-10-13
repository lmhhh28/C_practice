#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode {
    ElemSet data;  /* 存储数据*/
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode {
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

void Insert (List list, int i, ElemSet x);
void Remove ( List list, int i );

int main(void)
{
    int i, n, x;
    Position p;
    List list;
    
    list = (List)malloc(sizeof(struct HeadNode));
    list->head = (Position)malloc(sizeof(struct ListNode)); /* 创建空头结点 */;
    list->head->next = NULL;
    list->length = 0;
    scanf("%d: ", &n);
    for (i=1; i<=n; i++) {
        scanf("%d", &x);
        Insert(list, i, x);
    }
    scanf("%d", &i);
    if (scanf("%d", &x)!=EOF) {
        Insert(list, i, x);
    }
    else {
        Remove(list, i);
    }
    printf("%d:", list->length);
    p = list->head->next;
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    return 0;
}

void Insert (List list, int i, ElemSet x) {
    if(i < 1 || i > list->length + 1) {
        printf("ERROR\n");
    } else {
        Position ins = (Position)malloc(sizeof(struct ListNode));
        Position* p = &list->head;
        for(int j = 0; j < i; ++j) {
            p = &((*p)->next);
        }
        ins->next = *p;
        *p = ins;
        ins->data = x;
        ++list->length;
    }  
}

void Remove ( List list, int i ) {
    if(i < 1 || i > list->length) {
        printf("ERROR\n");
    } else {
        Position* p = &list->head, temp;
        for(int j = 0; j < i; ++j) {
            p = &((*p)->next);
        }
        temp = *p;
        *p = (*p)->next;
        free(temp);
        --list->length;
    }
}
