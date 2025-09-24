#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 100
typedef enum { false, true } bool;

typedef int ElemSet;
typedef int Position;  /* 整型下标，表示元素的位置 */
typedef struct ArrNode *ArrPtr;
struct ArrNode {
    ElemSet *data; /* 存储数据的数组；ElemSet是用户定义的数据类型 */
    int size;      /* 数组的大小 */
};

bool DecrSeqInsert( ArrPtr array, ElemSet x );

int main(void)
{
    int i, n;
    ArrPtr array;
    ElemSet x;
    
    array = (ArrPtr)malloc(sizeof(struct ArrNode));
    scanf("%d", &n);
    array->size = n;
    array->data = (int *)malloc(sizeof(int) * kMaxSize);
    for (i=0; i<n; i++) {
        scanf("%d", &array->data[i]);
    }
    scanf("%d", &x);
    if (DecrSeqInsert(array, x) == false) {
        printf("Insertion failed.\n");
    }
    printf("%d", array->data[0]);
    for (i=1; i<array->size; i++) {
        printf(" %d", array->data[i]);
    }
    printf("\n");
    printf("Array size = %d\n", array->size);
    
    return 0;
}

bool DecrSeqInsert( ArrPtr array, ElemSet x ) {
    bool flag = false;
    if(array->size < kMaxSize) {
        for(int i = array->size - 1; i >= 0; --i) {
            if(i == array->size - 1) {
                if(x < array->data[i]) {
                    array->data[i+1] = x;
                    flag = true;
                    array->size++;
                    break;
                }
            }
            if(x > array->data[i] && x < array->data[i - 1]) {
                flag = true;
                for(int j = array->size - 1; j >= i; --j) {
                    array->data[j+1] = array->data[j];
                }
                array->data[i] = x;
                array->size++;
                break;
            }
            if(i == 0 && x > array->data[i]) {
                flag = true;
                for(int j = array->size - 1; j >= i; --j) {
                    array->data[j+1] = array->data[j];
                }
                array->data[i] = x;
                array->size++;
                break;
            }
        }
    }
    return flag;
}