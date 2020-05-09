/* *************
 * 二叉堆实现
 * ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_heap.h"

#define MIN_DATA    0

/* ******
 * 初始化，分配内存
 * ***/
pHeap Initialize(int MaxHeapSize) {
    pHeap H = (pHeap)malloc(sizeof(struct HeapStruct));
    H->capacity = MaxHeapSize;
    H->size = 0;
    H->value = (int *)malloc(sizeof(int) * (MaxHeapSize + 1));
    H->value[0] = MIN_DATA;
    return H;
}

void Destory(pHeap H) {
    if(H != NULL) {
        free(H->value);
        free(H);
    }
}

void MakeEmpty(pHeap H) {
    if(H == NULL) {
        printf("不能将清空NULL堆\n");
        return;
    }
    H->size  = 0;
}

void Insert(int X, pHeap H) {
    if(IsFull(H)) {
        printf("栈满，无法插入\n");
        return;
    }
    int insert_index = ++H->size;   // 空穴位置
    int parent = insert_index/2;
    while(H->value[parent] > X) {
        H->value[insert_index] = H->value[parent];
        insert_index = parent;
        parent /= 2;
    }
    H->value[insert_index] = X; 
}

int DeleteMin(pHeap H) {
    if(H == NULL) {
        printf("不能对NULL堆删除元素\n");
        return MIN_DATA;
    }
    if(IsEmpty(H)) {
        printf("栈空，无法删除\n");
        return MIN_DATA;
    }
    int last_d = H->value[H->size--];
    int min_d = H->value[1];
    int delete_index = 1;   // 空穴，root
    int child = 2;
    // 比较空穴儿子大小，再比较小儿子和最后一个元素大小
    // 如过儿子小则儿子插入空穴，再次比较，否则元素插入空穴，结束
    // 注意有一个还是两个儿子，空穴没有儿子时结束
    while(delete_index * 2 < H->size) {
        if(H->size !=  child && H->value[child] > H->value[child + 1]) {
            // 有右儿子且右小于左，则右
            child++;
        }
        if(H->value[child] < last_d) {
            H->value[delete_index] = H->value[child];
            delete_index = child;
            child = delete_index * 2;
        }
        else {
            break;
        }
    }
    H->value[delete_index] = min_d; 
    return min_d;
}

int FindMin(pHeap H) {
    if(H == NULL || H->size == 0) {
        printf("栈为空或NULL");
        return MIN_DATA;
    }
    return H->value[1];
}

int IsEmpty(pHeap H) {
    if(H == NULL) {
        printf("错误，堆为NULL");
        return true;
    }
    if(H->capacity == H->size) {
        return true;
    }
    else {
        return false;
    }
    
}

int IsFull(pHeap H) {
    if(H == NULL) {
        printf("错误，堆为NULL");
        return false;
    }
    if(0 == H->size) {
        return true;
    }
    else {
        return false;
    }
}

/* ********
 * 下滤操作
 * 2*i < H->size 有右儿子 等于则只有左儿子
 * 
 * *****/
static void PercolateDown(pHeap H, int i) {
    int child_index = 2*i;
    if(2*i < H->size && \
            H->value[child_index] > H->value[child_index + 1]) {
        child_index++;
    }
    if(H->value[i] > H->value[child_index]) {
        int temp = H->value[i];
        H->value[i] = H->value[child_index];
        H->value[child_index] = temp;
    }
}

pHeap BuildHeap(int *data, int n) {
    pHeap H = Initialize(n);
    H->value = (int *)malloc(sizeof(int) * n);
    memcpy(H->value, data, sizeof(int)*n);
    H->size = n;
    for(int i = n/2; i > 0; i++) {
        PercolateDown(H, i);
    }
    return H;
}

