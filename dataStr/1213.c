#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode {
    ElemSet data;  /* 存储数据 */
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode {
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

void PrintList( List list )
{ /* 顺序输出链表结点数据 */
    Position p;
    
    p = list->head->next; /* p指向第1个结点 */
    int flag = 0;
    while (p) {
        if(!flag) {
            printf("%d", p->data);
            flag = 1;
        } else {
            printf(" %d", p->data);
        }
        p = p->next;
    }
}

List JosephusProblem( int n, int m ) {
    List list = (List)malloc(sizeof(struct HeadNode));
    List res = (List)malloc(sizeof(struct HeadNode));
    list->length = n;
    list->head = (Position)malloc(sizeof(struct ListNode));
    res->head = (Position)malloc(sizeof(struct ListNode));
    Position p = list->head, q = res->head;
    for(int i = 0; i < n; ++i) {
        Position node = (Position)malloc(sizeof(struct ListNode));
        node->data = i+1;
        node->next = NULL;
        p->next = node;
        p = p->next; 
    }
    p->next = list->head->next;
    p = p->next;
    while(list->length > 0) {
        for(int i = 0; i < m - 2; ++i) {
            p = p->next;
        }
        q->next = p->next;
        q = q->next;
        p->next = p->next->next;
        --list->length;
        p = p->next;
    }
    q->next = NULL;
    return res;
}

int main(void)
{
    List list;
    int n, m;
    scanf("%d %d", &n, &m);
    list = JosephusProblem(n, m);
    PrintList( list );
    return 0;
}