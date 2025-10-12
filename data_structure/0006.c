#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *PtrToNode; /* 指针即结点位置 */
struct ListNode {
    ElemSet data;  /* 存储数据 */
    PtrToNode next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode {
    PtrToNode head; /* 单链表头指针 */
    int length;    /* 表长 */
};

List ReadInput()
{ /* 读输入，创建带头结点的单链表 */
    int n, i;
    List list;
    PtrToNode tail, new_node;
    
    list = (List)malloc(sizeof(struct HeadNode));
    list->head = (PtrToNode)malloc(sizeof(struct ListNode)); /* 创建空头结点 */
    scanf("%d", &n);
    list->length = n;
    tail = list->head; /* 初始化尾指针 */
    for (i=0; i<n; i++) {
        new_node = (PtrToNode)malloc(sizeof(struct ListNode));
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        tail->next = new_node; /* 插入表尾 */
        tail = new_node;
    }
    return list;
}

void PrintList( List list )
{ /* 顺序输出链表结点数据 */
    PtrToNode p;
    
    p = list->head->next; /* p指向第1个结点 */
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

PtrToNode Cut(List list, int n) {
    PtrToNode p = list->head, temp;
    for(int i = 1; i < n; ++i) {
        p = p->next;
    }
    temp = p->next;
    p->next = temp->next;
    temp->next = NULL;
    --list->length;
    return temp;
}

void Insert(List list, PtrToNode node, PtrToNode p) {
    node->next = p->next;
    p->next = node;
    ++list->length;
}

List InitList() {
    List list = (List)malloc(sizeof(struct HeadNode));
    list->head = (PtrToNode)malloc(sizeof(struct ListNode));
    list->head->next = NULL;
    list->length = 0;
    return list;
}

void K_Reverse( List list, int k ) {
    List res = InitList();
    int len = list->length;
    PtrToNode pos = res->head, tail;
    for(int i = 1; i+k <= len+1; i+=k) {
        for(int j = 0; j < k; ++j) {
            Insert(res, Cut(list, 1), pos);
            if(!j) {
                tail = pos->next;
            }
        }
        pos = tail;
    }
    pos->next = list->head->next;
    list->head->next = res->head->next;
}



int main(void)
{
    List list;
    int k;

    list = ReadInput();
    scanf("%d", &k);
    K_Reverse( list, k );
    PrintList( list );

    return 0;
}

