/*************************************************************************
    > File Name: sorting.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月20日 星期三 09时33分20秒
 ************************************************************************/

#ifndef _SORTING_H_C
#define _SORTING_H_C
typedef int ElemType;

void PrintArray(ElemType A[], int N);
void InsertionSort_withSwap(ElemType A[], int N);
void InsertionSort(ElemType A[], int N);
void ShellSort(ElemType A[], int N);
void HeapSort(ElemType A[], int N);
void MergeSort(ElemType A[], int N);
void QuickSort(ElemType A[], int N);
extern void QuickSelect(ElemType A[], int N, int k);
void CountSort(int A[], int N);
void RadixSort(int A[], int N);
void CountSort_withRange(int A[], int N, int MinElem, int MaxElem);



#endif /* SORTING_H_C */
