#include <stdio.h>
#include <stdlib.h>
#define DEF 1024
#define Carry_space DEF / 2
typedef struct{
    char *HEAD;
    char *top,*bottom;
    int vol;
}Block;

void Init_block(Block *p);
void Delete_block(Block *p);
void Input(Block *p);
void Output(Block *p);
void Add_eq(Block *p,Block *q);
void Add_su(Block *p,Block *q,Block *s);
void Mutip_double_su(Block *p,Block *q,Block *s);
void Copy_int(Block *p,int num);
void Copy_Block(Block *p,Block *q);
void Refresh(Block *p);

int main(){ 
    
    // -----------------------------------------------            
                
            // Block Auged,Aug,Add,Sum;
            // Init_block(&Auged);Init_block(&Aug);
            // Input(&Auged);Input(&Aug);
            // Add_eq(&Auged,&Aug);
            // Output(&Auged);
    
            // Block fact_1,fact_2,pro;
            // Init_block(&fact_1);Init_block(&fact_2);Init_block(&pro);
            // Input(&fact_1);Input(&fact_2);
            // Mutip_double_su(&fact_1,&fact_2,&pro);
            // Output(&pro);
    
    // -----------------------------------------------

    int n;scanf("%d",&n);
    Block pro,sum,pro_temp,temp;
    Init_block(&pro);Init_block(&sum);Init_block(&pro_temp);Init_block(&temp);
    Copy_int(&pro_temp,1);Copy_int(&sum,0);
    for(int i = 1;i <= n;i ++){
        Refresh(&temp);
        Copy_int(&temp,i);
        Mutip_double_su(&pro_temp,&temp,&pro);
        Add_eq(&sum,&pro);
        Copy_Block(&pro,&pro_temp);
        Refresh(&pro);
    }
    Output(&sum);

}

void Init_block(Block *p){
    p->HEAD = (char*)malloc(DEF);
    for(int i = 0;i < DEF;i ++){
        p->HEAD[i] = 0; 
    }
    p->top = p->bottom = p->HEAD + Carry_space;
    p->vol = 0;
}

void Refresh(Block *p){
    for(int i = 0;i < DEF;i ++){
        p->HEAD[i] = 0; 
    }
    p->top = p->bottom = p->HEAD + Carry_space;
    p->vol = 0;
}

void Delete_block(Block *p){
    free(p->HEAD);
    p->top = p->bottom = NULL;
    p->vol = 0;
}

void Input(Block *p){
    char ch;
    while((ch = getchar()) != '\n'){
        *(p->bottom ++) = ch - '0';
        p->vol ++;
    }
    p->bottom --;
}

void Output(Block *p){
    int volume = p->vol;
    for(int i = 0;i < volume;i ++){
        if((p->top)[0] == 0){
            printf("%d",0);
            break;
        }
        printf("%d",(p->top)[i]);
    }
    printf("\n");    
}

void Add_eq(Block *p,Block *q){
    char *operator_p = p->bottom,*operator_q = q->bottom;
    for(;operator_p - p->top >= 0 || operator_q - q->top >= 0;operator_p --,operator_q --){
        *operator_p += *operator_q; 
    }
    p->top = operator_p + 1;operator_p = p->bottom;
    for(;operator_p >= p->top;operator_p --){
        *(operator_p - 1) += *operator_p / 10;
        *operator_p %= 10; 
    }
    if(*(p->top - 1) != 0){
        p->top --;
    }
    p->vol = p->bottom - p->top + 1;
}

void Mutip_double_su(Block *p,Block *q,Block *s){
    char *operator_p = p->bottom,*operator_q = q->bottom;
    Block pro_temp;
    Init_block(&pro_temp);
    int count = 0;
    for(;operator_q >= q->top;operator_q --){
        Refresh(&pro_temp);
        for(operator_p = p->bottom;operator_p >= p->top;operator_p --){
            *(pro_temp.top --) = *operator_q * *operator_p;
            pro_temp.vol ++;
        }
        char *operator_temp = pro_temp.bottom;
        for(;operator_temp != pro_temp.top + 1;operator_temp --){
            *(operator_temp - 1) += *operator_temp / 10;
            *operator_temp %= 10;
        }
        if(*pro_temp.top == 0){
            pro_temp.top ++;
        }else{
            pro_temp.vol ++;
        }
        pro_temp.bottom += count;pro_temp.vol += count;
        Add_eq(s,&pro_temp);
        count ++;
    }
}

void Copy_int(Block *p,int num){
    while(num > 0){
        *(p->top --) = num % 10;
        num /= 10;
        p->vol ++;
    }
    p->top ++;
}

void Copy_Block(Block *p,Block *q){
    Refresh(q);
    char *operator = p->bottom;
    for(;operator >= p->top;operator --){
        *(q->top --) = *operator;
    }
    q->top ++;
    q->vol = p->vol;
}


