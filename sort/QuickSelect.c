/*************************************************************************
    > File Name: QuickSelect.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年06月12日 星期五 13时12分17秒
 ************************************************************************/

#include <stdio.h>
#include "sorting.h"

extern ElemType QuickSort_Pivot(ElemType A[], int N);
extern void SwapElem(ElemType *a, ElemType *b);

// 元素个数不大于这个值时直接使用插入排序
#define CUT_OFF_NUM     5

/* **********
 * 快速选择算法：选择排序数组第k个最小的数
 * *******/
void QuickSelect(ElemType A[], int N, int k) {
    if(N <= CUT_OFF_NUM) {
        InsertionSort(A, N);
        return;
    }
    ElemType iPivot = QuickSort_Pivot(A, N);
    int i = 0, j = N - 2;
    while(1) {
        while(A[++i] < iPivot) {}
        while(A[--j] > iPivot) {}
        if(i < j) {SwapElem(A + i, A + j);}
        else {break;}
    }
    SwapElem(A + i, A + N - 2);
    if(k <= i) {
        QuickSelect(A, i, k);
    }
    else if(k > i + 1) {
        QuickSelect(A + (i + 1), N - (i + 1), k - (i + 1));
    }
}
