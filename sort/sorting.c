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

void SwapElem(ElemType *a, ElemType *b) {
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

// 当快速排序元素个数小于CUT_OFF_NUM时使用插入排序
#define CUT_OFF_NUM     6

/* **********
 * 快速排序枢纽元选择
 * 使用三数中值分割法
 * *******/
ElemType QuickSort_Pivot(ElemType A[], int N) {
    int iCenterIndex = N/2;
    int iLastIndex = N - 1;
    if(A[0] > A[iCenterIndex]) {
        SwapElem(A, A + iCenterIndex);
    }
    if(A[iCenterIndex] > A[iLastIndex]) {
        SwapElem(A + iCenterIndex, A + iLastIndex);
    }
    if(A[0] > A[iCenterIndex]) {
        SwapElem(A, A + iCenterIndex);
    }
    SwapElem(A + iCenterIndex, A + iLastIndex - 1);
    return A[iLastIndex - 1];
}

/* **********
 * 快速排序
 * *****/
void QuickSort(ElemType A[], int N) {
    if(N <= CUT_OFF_NUM) {
        InsertionSort(A, N);
        return;
    }
    ElemType iPivot = QuickSort_Pivot(A, N);
    int i = 0, j = N - 2;
    while(1) {
        while(A[++i] < iPivot) {}
        while(A[--j] > iPivot) {}
        // 注意：以下写法时错的，在A[i]=A[j]=iPivot时会进入无限循环！！！
        // while(A[i] < iPivot) {i++;}
        // while(A[j] > iPivot) {j--;}
        if(i < j) {
            SwapElem(A + i, A + j);
        }
        else {
            break;
        }
    }
    SwapElem(A + i, A + N - 2);
    QuickSort(A, i);
    QuickSort(A + (i + 1), N - (i + 1));
}

/* **********
 * 指定参数范围的计数排序
 * *****/
void CountSort_withRange(int A[], int N, int MinElem, int MaxElem) {
    int iii = 0, jjj = 0;
    int iCountNum = MaxElem - MinElem + 1;
    // 计数
    int *C = (int *)malloc(iCountNum * sizeof(int));
    memset(C, '\0', sizeof(int) * iCountNum);
    for(iii = 0; iii < N; iii++) {
        C[A[iii] - MinElem]++;
    }
    // 反向填充
    for(iii = 0; iii < iCountNum; iii++) {
        while(C[iii]-- > 0) {
            A[jjj++] = iii;
        }
    }
    free(C);
}


/* ***********
 * 计数排序：假设输入为一定范围内的整数
 * ****/
void CountSort(int A[], int N) {
    // 寻找最大值和最小值
    int MaxElem = A[0], MinElem = A[0];
    for(int iii = 0; iii < N; iii++) {
        if(A[iii] > MaxElem) {
            MaxElem = A[iii];
        }
        if(A[iii] < MinElem) {
            MinElem = A[iii];
        }
    }
    CountSort_withRange(A, N, MinElem, MaxElem);
}

// 基数排序基数二进制位数（4即基数为16）
#define RADIX_BASE_BINARY   4
typedef struct RADIX_STRUCT {
    int base;   // 基数值
    int value;  // 原始值
} tsRadixStruct;

static void Print_RadixStruct(tsRadixStruct A[], int N) {
    printf("\n");
    for(int iii = 0; iii < N; iii++) {
        printf("base = %d, value = %d = %X\n", A[iii].base, A[iii].value, A[iii].value);
    }
}

/* **********
 * 使用计数排序对基数结构体排序
 * ******/
void CountSort_Struct(tsRadixStruct A[], int N, int iCountNum) {
    int iii = 0;
    int *B = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc((iCountNum) * sizeof(int));
    memset(C, '\0', sizeof(int) * (iCountNum+ 1));
    memset(B, '\0', sizeof(int) * N);
    // 计数
    for(iii = 0; iii < N; iii++) {
        C[A[iii].base]++;
    }
    // 累加，累加后对应位置存储的数据即其存储的位置    
    for(iii = 1; iii < iCountNum; iii++) {
        C[iii] += C[iii - 1];
    }
    // 反向填充
    for(iii = N - 1; iii >= 0; iii--) {
        B[--C[A[iii].base]] = A[iii].value;
    }
    for(iii = 0; iii < N; iii++) {
        A[iii].value = B[iii];
    }
    free(C);
    free(B);
}

/* *********
 * 基数排序：假设输入正整数
 * *****/
void RadixSort(int A[], int N) {
    int iRadixBase = (1 << RADIX_BASE_BINARY) - 1;
    int iii = 0, jjj = 0;
    tsRadixStruct *A_Struct = (tsRadixStruct *)malloc(sizeof(tsRadixStruct) * N);
    for(iii = 0; iii < N; iii++) {
        A_Struct[iii].value = A[iii];
    }
    for(iii = 0; iii < 32/ RADIX_BASE_BINARY; iii++) {
        // 计算base值
        for(jjj = 0; jjj < N; jjj++) {
            A_Struct[jjj].base = (A_Struct[jjj].value >> (iii*RADIX_BASE_BINARY)) & iRadixBase;
        }
        // 排序
        CountSort_Struct(A_Struct, N, iRadixBase + 1);
    }
    for(iii = 0; iii < N; iii++) {
        A[iii] = A_Struct[iii].value;
    }
    free(A_Struct);
}

