#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int volume;
    int *base;
    int *top;
    int *locate;
}stack;

int Init(stack *p,int volume);
int Push(stack *p,int num);
int Pop(stack *p);
int Locate(stack *p,int location);
int Get(stack *p,int location);
int Free(stack *p);

int main(){
    stack example;
    scanf("%d",&example.volume);
    example.locate = example.top = example.base = (int*)(malloc(example.volume * sizeof(int)));
    for(int i = 0;i < example.volume;i ++){
        int num;
        scanf("%d",&num);
        Push(&example,num);
    }
    printf("%d\n",example.top - example.base);
    for(int i = 0;i < example.volume;i ++){
        printf("%d ",Get(&example,i));
    }
    printf("\n");
}

int Push(stack *p,int num){
    int state = 0;
    if((p -> top) - (p -> base) < (p -> volume)){
        state = 1;
        *(p -> top ++) = num;
    }
    return state;
}

int Pop(stack *p){
    int state = -1;
    if(p -> top != p -> base){
        state = 1;
        (p -> top) --;
    }
    return state;
}

int Locate(stack *p,int location){
    int state = -1;
    if(location < (p -> top) - (p -> base)){
        state = 1;
        p -> locate += location;
    }
    return state;
}

int Get(stack *p,int location){
    int state = -1;
    if((state = Locate(p,location)) == 1)
        state = *(p -> locate);
    p -> locate = p -> base;
    return state;
}