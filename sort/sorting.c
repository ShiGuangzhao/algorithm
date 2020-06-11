/*************************************************************************
    > File Name: sorting.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月20日 星期三 09时32分33秒
    > 介绍：升序排序算法
 ******************* *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

static void SwapElem(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(ElemType A[], int N) {
    for(int iii = 0; iii < N; iii++) {
        printf("%d\t", A[iii]);
    }
    printf("\n");
}

/* **********
 * 使用了交换的插入排序
 * *****/
void InsertionSort_withSwap(ElemType A[], int N) {
    int iii, jjj;
    for(iii = 1; iii < N; iii++) {
        for(jjj = iii; jjj > 0 && A[jjj] < A[jjj-1]; jjj--) {
            SwapElem(&A[jjj], &A[jjj-1]);
        }
    }
}

/* *********
 * 插入排序
 * 一种避免显式交换的方法，减少赋值次数
 * ******/
void InsertionSort(ElemType A[], int N) {
    int iii, jjj;
    ElemType Ap;
    for(iii = 1; iii < N; iii++) {
        Ap = A[iii];
        for(jjj = iii; jjj > 0 && A[jjj-1] > Ap; jjj--) {
            A[jjj] = A[jjj-1];
        }
        A[jjj] = Ap;
    }
}

/* ********
 * 希尔排序，使用增量序列为N/2, N/4, ...
 * ***/
void ShellSort(ElemType A[], int N) {
    int iii, jjj, hk;
    ElemType Ap;
    for(hk = N/2; hk >= 1; hk /= 2) {
        // 注意是 iii++ 而不是 iii+=hk，保证每个相隔hk处均排序 
        for(iii = hk; iii < N; iii++) {
            Ap = A[iii];
            for(jjj = iii; jjj > 0 && A[jjj - hk] > Ap; jjj -= hk) {
                A[jjj] = A[jjj-hk];
            }
            A[jjj] = Ap;
        }
    }
}

#define LEFT_CHILD(i)   (2*i + 1)

/* ***********
 * 下滤操作
 * *****/
static void HeapSort_PercDown(ElemType A[], int iii, int N) {
    int MaxChildIndex = 0;
    ElemType Temp = A[iii];
    for (; LEFT_CHILD(iii) < N; iii = MaxChildIndex) {
        MaxChildIndex = LEFT_CHILD(iii);
        if(MaxChildIndex < N - 1 && \
                A[MaxChildIndex] < A[MaxChildIndex + 1]) {
            MaxChildIndex++;
        }
        // 以此避免显示的交换，可以减少赋值次数，但需要注意设置break条件
        if(Temp < A[MaxChildIndex]) {
            A[iii] = A[MaxChildIndex];
        }
        else {
            break;
        }
    }
    A[iii] = Temp;
}

/* ********
 * 构建Max堆操作
 * 位置0需要存放元素
 * left = 2*parent + 1, right = 2*parent+2
 * ****/
static void HeapSort_Init(ElemType A[], int N) {
    int MaxChildIndex = 0;
    for(int iii = N/2 - 1; iii >= 0; iii--) {
        for (int jjj = iii; LEFT_CHILD(jjj) < N; jjj = MaxChildIndex) {
            MaxChildIndex = LEFT_CHILD(jjj);
            if(MaxChildIndex < N - 1 && \
                    A[MaxChildIndex] < A[MaxChildIndex + 1]) {
                MaxChildIndex++;
            }
            if(A[jjj] < A[MaxChildIndex]) {
                SwapElem(&A[jjj], &A[MaxChildIndex]);
            }
        }
    }
}

/* *********
 * DeleteMax并将弹出元素放到末尾
 * *****/
static void HeapSort_DeleteMax(ElemType A[], int N) {
    ElemType MaxElem = A[0];
    ElemType lastElem = A[N-1];
    ElemType MaxChildIndex = 0;
    int deleteIndex = 0;
    while(deleteIndex < N/2 - 1) {
        MaxChildIndex = LEFT_CHILD(deleteIndex);     // 左儿子
        if(MaxChildIndex + 1 < N && \
                A[MaxChildIndex] < A[MaxChildIndex + 1]) {
            MaxChildIndex++;
        }
        if(A[MaxChildIndex] > lastElem) {
            A[deleteIndex] = A[MaxChildIndex];
            deleteIndex = MaxChildIndex;
        }
        else {
            break;
        }
    }
    A[deleteIndex] = lastElem;
    A[N-1] = MaxElem;
}

/* *********
 * 堆排序，不适用额外数组空间
 * *****/
void HeapSort(ElemType A[], int N) {
    // 构建堆
    for(int iii = N/2 - 1; iii >= 0; iii--) {
        HeapSort_PercDown(A, iii, N);
    }
    // 排序，注意从N 开始
    for(int iii = N - 1; iii > 0; iii--) {
        SwapElem(&A[0], &A[iii]);
        HeapSort_PercDown(A, 0, iii);
    }
}

/* *********
 * 归并递归函数
 * 如果N > 1，分为两个数组排序后合并
 * ******/
void Merge(ElemType A[], int N, ElemType TempArray[]) {
    if(N == 1) {
        return;
    }
    int iLeftLength = N/2;
    Merge(A, iLeftLength, TempArray);
    Merge(A + iLeftLength, N - iLeftLength, TempArray);
    int iLeftIndex = 0, iRightIndex = iLeftLength, iTempIndex = 0;
    while(iLeftIndex < iLeftLength && iRightIndex < N) {
        if(A[iLeftIndex] < A[iRightIndex]) {
            TempArray[iTempIndex++] = A[iLeftIndex++];
        }
        else {
            TempArray[iTempIndex++] = A[iRightIndex++];
        }
    }
    if(iLeftIndex == iLeftLength) {
        memcpy((char *)(TempArray + iTempIndex), \
                (char *)(A + iRightIndex), \
                (N - iRightIndex) * sizeof(ElemType));
    }
    else {
        memcpy((char *)(TempArray + iTempIndex), \
                (char *)(A + iLeftIndex), \
                (iLeftLength - iLeftIndex) * sizeof(ElemType));
    }
    memcpy((char *)A, (char *)TempArray, N * sizeof(ElemType));
}


/* *********
 * 归并排序，使用一个临时数组以节约内存
 * *****/
void MergeSort(ElemType A[], int N) {
    ElemType *TempArray = (ElemType *)malloc(sizeof(ElemType) * N);
    Merge(A, N, TempArray);
    free(TempArray);
}
