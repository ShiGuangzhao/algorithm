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
    int NodeNum = 20;
    int xRange = 50;
    int yRange = 50;
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
    PrintPoints(P, NodeNum);
    SortPoint_InsertionSort(P, NodeNum, GetPonit_x);
    PrintPoints(P, NodeNum);



    /* double d_min = GetNearPoints(P, NodeNum, NearPonit); */

    /* printf("最近节点为(%d, %d)和(%d, %d)，距离为%f\n", NearPonit[0].x, NearPonit[0].y, NearPonit[1].x, NearPonit[1].y, d_min); */

}

int main(void) {
    TestNearPonint();
    return 0;
}
