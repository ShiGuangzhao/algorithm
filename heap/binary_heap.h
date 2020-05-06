/*************************************************************************
    > File Name: binary_heap.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月06日 星期三 14时29分11秒
 ************************************************************************/

#ifndef _BINARY_HEAP_H_C
#define _BINARY_HEAP_H_C
struct HeapStruct {
    int capacity;
    int size;
    int *value;
};

typedef struct HeapStruct *pHeap;

pHeap Initialize(int HeapSize);
void Destory(pHeap H);
void MakeEmpty(pHeap H);
void Insert(int X, pHeap H);
int DeletMin(pHeap H);
int FindMin(pHeap H);
int IsEmpty(pHeap H);
int IsFull(pHeap H);

#endif /* BINARY_HEAP_H_C */
