/*************************************************************************
    > File Name: key_sort.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月18日 星期六 14时56分47秒
 ************************************************************************/

#include <stdio.h>
#include "../sort/sorting.h"
#include "divide_conquer.h"

int GetPonit_x(tsPoint p) {
    return p.x;
}

int GetPonit_y(tsPoint p) {
    return p.y;
}

/* *********
 * 依据函数指针指定的值排序，返回排序顺序数组
 * *****/
void SortPoint_InsertionSort(tsPoint A[], int PonitsNum, int (*key)(tsPoint p)) {
    int iii, jjj;
    tsPoint Ap;
    for(iii = 1; iii < PonitsNum; iii++) {
        Ap = A[iii];
        for(jjj = iii; jjj > 0 && key(A[jjj-1]) > key(Ap); jjj--) {
            A[jjj] = A[jjj-1];
        }
        A[jjj] = Ap;
    }
}

void PrintPoints(tsPoint P[], int NodeNum) {
    printf("--------------------------------\n");
    for(int i = 0; i < NodeNum;i++ ) {
        printf("Node %d:  (x, y) = (%d, %d)\n", i, P[i].x, P[i].y);
    }
    printf("--------------------------------\n");
}
