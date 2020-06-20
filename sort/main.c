/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 1919年05月19日 星期三 09时41分56秒
 ************************************************************************/

#include <stdio.h>
#include "sorting.h"
#include <string.h>

int main(void) {
    int A[10] = {1, 2, 6, 3, 0, 9, 7, 6, 5, 6};
    int B[19] = {1, 2, 4, 6, 11, 41, 31, 10, 91, 3, 0, 9, 7, 8, 5, 71, 81, 51, 16};
    PrintArray(A, 10);
    PrintArray(B, 19);
    RadixSort(A, 10);
    RadixSort(B, 19);
    /* PrintArray(A, 10); */
    /* QuickSort(A, 10); */
    /* QuickSort(B, 19); */
    /* MergeSort(A, 10); */
    /* MergeSort(B, 19); */
    /* HeapSort(A, 10); */
    /* ShellSort(A, 10); */
    /* InsertionSort(A, 10); */
    /* InsertionSort_withSwap(A, 10); */
    PrintArray(A, 10);
    PrintArray(B, 19);
}
