/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月18日 星期六 11时14分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "divide_conquer.h"

void TestNearPonint(void) {
    int NodeNum = 3000;
    int xRange = 1000;
    int yRange = 1000;
    srand((unsigned)time(NULL)); 
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

int main(void) {
    TestNearPonint();
    return 0;
}
