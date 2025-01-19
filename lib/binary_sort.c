#include <stdio.h>
#include <stdlib.h>

void swap(int *p,int *q);
void sort(int *p,int lenth);
int max(int *p,int lenth);
int recur_max(int *p,int lenth,int top);
int recur_sort(int *p,int lenth,int top);
int binary(int *p,int lenth,int num);
int recur_binary(int *p,int lenth,int num,int top,int bottom); 

int main(){
    int lenth,num;scanf("%d",&lenth);
    int *arr = (int*)(malloc(lenth * sizeof(int)));
    for(int i = 0;i < lenth;i ++){
        scanf("%d",arr + i);
    }
    printf("%d\n",recur_max(arr,lenth,0));
    recur_sort(arr,lenth,0);
    //sort(arr,lenth);
    for(int i = 0;i < lenth;i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    scanf("%d",&num);
    printf("%d\n",binary(arr,lenth,num));
    printf("%d\n",recur_binary(arr,lenth,num,0,5));
}

void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void sort(int *p,int lenth){
    for(int i = 0;i < lenth;i ++){
        for(int j = i;j < lenth;j ++){
            if(p[i] > p[j])
                swap(p + i,p + j);
        }
    }
}

int recur_sort(int *p,int lenth,int top){
    if(top == lenth - 1)
        return 1;
    else{
        for(int i = top;i < lenth;i ++){
            if(p[top] > p[i])
                swap(p + top,p + i);
        }
        recur_sort(p,lenth,top + 1);
    }
}

int max(int *p,int lenth){
    int temp = p[0];
    for(int i = 0;i < lenth;i ++){
        if(temp < p[i])
            temp = p[i];
    }
    return temp;
}

int recur_max(int *p,int lenth,int top){
    return top == lenth - 1 ? p[top] : p[top] > recur_max(p,lenth,top + 1) ? p[top] : recur_max(p,lenth,top + 1);
}


int binary(int *p,int lenth,int num){
    int state = -1;
    int top = 0,bottom = lenth - 1;
    while(bottom != top || p[bottom] == num){
        if(p[bottom] == num){
            state = bottom;
            break;
        }
        else
            p[(top + bottom) / 2] < num ? (top = (top + bottom) / 2) : (bottom = (top + bottom) / 2);

    }
    return state;
}

int recur_binary(int *p,int lenth,int num,int top,int bottom){
    return top == bottom && p[top] != p[bottom] ? -1 : p[bottom] == num ? bottom : p[(top + bottom) / 2] < num ? recur_binary(p,lenth,num,(top + bottom) / 2,bottom) : recur_binary(p,lenth,num,top,(top + bottom) / 2);
}