#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *last;
    struct node *next;
}node;
typedef struct linked_list{
    int lenth;
    node *locate;
    node *head;
    node *tail;
}linked_list;
void Locate(linked_list *p,int num);
int Get_value(linked_list *p,int num);
void Delete_node(linked_list *p,int num);
void Modify_value(linked_list *p,int num,int new_value);
void Trans(linked_list *p,int num);
int main()
{
    int num;scanf("%d",&num);
    for(int i = 0;i < num;i ++){
        linked_list example;
        scanf("%d",&example.lenth);
        example.head = (node*)(malloc(sizeof(node)));
        example.tail = example.head;
        getchar();
        for(int i = 0;i < example.lenth;i ++){
            char ch = getchar();
            if(ch == 'U')
                example.tail -> value = 1;
            else
                example.tail -> value = 0;
            if(i == example.lenth - 1){
                example.tail -> next = example.head;
                break;
            }
            example.tail -> next = (node*)(malloc(sizeof(node)));
            (example.tail -> next) -> last = example.tail; 
            example.tail = example.tail -> next;
        }
        example.head -> last = example.tail;
        
        /* //printf("%d\n",(example.head) -> value);
        Trans(&example,0);
        //Delete_node(&example,0);
        for(int i = 0;i < example.lenth;i ++)
            printf("%d\n",Get_value(&example,i));
        //printf("\n"); */
        
        int count = 0,ret;
        do{
            ret = 0;
            if(example.lenth == 1){
                if(Get_value(&example,0) == 0)
                    break;
                else if(Get_value(&example,0) == 1){
                    count ++;
                    break;
                }
            }
            for(int i = 0;i < example.lenth;i ++){
                if(Get_value(&example,i) == 1){
                    ret = 1;count ++;
                    Trans(&example,i);
                    break;
                }
            }
            /* for(int i = 0;i < example.lenth;i ++){
                printf("%d ",Get_value(&example,i));
            }
            printf("\n"); */
        }while(ret == 1 && example.lenth > 0);
        //printf("%d\n",count);
        if(count % 2 == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
} 
void Locate(linked_list *p,int num){
    num = num % (p -> lenth);
    p -> locate = p -> head;
    for(int i = 0;i < num;i ++)
        p -> locate = (p -> locate) -> next;
}
int Get_value(linked_list *p,int num){
    Locate(p,num);
    int this_value = (p -> locate) -> value;
    p -> locate = p -> head;
    return this_value;    
}
void Delete_node(linked_list *p,int num){
    Locate(p,num);
    if(p -> lenth == 1){
        p -> head = NULL;
        p -> tail = NULL;
        free(p -> locate);
    }else{
        ((p -> locate) -> last) -> next = (p -> locate) -> next;
        ((p -> locate) -> next) -> last = (p -> locate) -> last;
        if(p -> locate == p -> head)
            p -> head = (p -> locate) -> next;
        free(p -> locate);
        p -> locate = p -> head;
        (p -> lenth) --;
    }
}
void Modify_value(linked_list *p,int num,int new_value){
    Locate(p,num);
    (p -> locate) -> value = new_value;
    p -> locate = p -> head;
}
void Trans(linked_list *p,int num){
    Locate(p,num);
    ((p -> locate) -> last) -> value ^= 1;
    ((p -> locate) -> next) -> value ^= 1;
    Delete_node(p,num); 
}