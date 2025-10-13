#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 10
#define NotFound -1

typedef int ElemSet;
typedef int Position;  /* 整型下标，表示元素的位置 */
typedef struct ArrNode *ArrPtr;
struct ArrNode {
    ElemSet *data; /* 存储数据的数组；ElemSet是用户定义的数据类型 */
    int size;      /* 数组的大小 */
};

Position BinarySearch( ArrPtr array, ElemSet x );

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int)*array->size); 
    for (i=0; i<n; i++) {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);
    printf("%d\n", BinarySearch(array, x));
    return 0;
}

Position BinarySearch( ArrPtr array, ElemSet x ) {
    Position top = (array->size) - 1, bottom = 0, flag = NotFound;
    while(1) {
        if(array->data[top] == x) {
            flag = top;
            break;
        }
        if(array->data[bottom] == x) {
            flag = bottom;
            break;
        }
        Position middle = (top + bottom) / 2;
        ElemSet num = array->data[middle];
        if(num == x) {
            flag = middle;
            break;
        }
        if(top - bottom == 1 && flag == NotFound) {
            break;
        } 
        if(num < x) {
            bottom = middle;
        } else {
            top = middle;
        }
    }
    return flag;
}