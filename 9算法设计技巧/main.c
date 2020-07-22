/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月18日 星期六 11时14分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "../commom/common.h"
#include "divide_conquer.h"
#include "randomized.h"

void TestNearPonint(void) {
    int NodeNum = 3000;
    int xRange = 1000;
    int yRange = 1000;
    tsPoint P[NodeNum];
    tsPoint NearPoint[2];
    pPoint P_temp = P;
    
    // 初始化节点
    for(int i = 0; i < NodeNum;i++ ) {
        P_temp->x = rand() % xRange;
        P_temp->y = rand() % yRange;
        P_temp++;
    }
    /* PrintPoints(P, NodeNum); */
    double beginclock = clock();
    double d_min = GetNearPoints_saveNearPoints(P, NodeNum, NearPoint);
    printf("1: 最近节点为(%d, %d)和(%d, %d)，距离为%f, clock = %f\n", \
            NearPoint[0].x, NearPoint[0].y, \
            NearPoint[1].x, NearPoint[1].y, d_min, clock() - beginclock);
    beginclock = clock();
    d_min = GetNearPoints_dq_saveNearPoints(P, NodeNum, NearPoint);
    /* SortPoint_InsertionSort(P, NodeNum, GetPoint_x); */
    printf("2: 最近节点为(%d, %d)和(%d, %d)，距离为%f, clock = %f\n", \
            NearPoint[0].x, NearPoint[0].y, \
            NearPoint[1].x, NearPoint[1].y, d_min, clock() - beginclock);
}

void TestMatrix(void) {
    pMatrix A = MatrixInit_Rand(5, 5, 3);
    pMatrix B = MatrixInit_Rand(5, 5, 3);
    pMatrix C = MatrixInit_Zero(5, 5);

    PrintMatrix(A);
    PrintMatrix(B);
    PrintMatrix(C);

    MatrixMultiply(A, B, C);
    PrintMatrix(C);

    MatrixDestory(A);
    MatrixDestory(B);
    MatrixDestory(C);
}

void TestRandom(void) {
    RandInit(time(NULL));
    LOOP_ADD(iii, 0,  20) {
        printf("%d\t", Random() % 20);
    }
    printf("\n");
    srand((unsigned)time(NULL)); 
    LOOP_ADD(iii, 0,  20) {
        printf("%d\t", rand() % 20);
    }
    printf("\n");
}

int main(void) {
    /* srand((unsigned)time(NULL));  */
    /* TestMatrix(); */
    TestRandom();
    return 0;
}
