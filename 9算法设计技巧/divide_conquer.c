/*************************************************************************
    > File Name: divide_conquer.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月18日 星期六 14时19分44秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "divide_conquer.h"
#include "../commom/common.h"

/* ************
 * 分治法解决最近点问题
 * P为输入点集，PonitsNum为点集中的点数，NearPoint为最近的两个点
 * 返回值为最短距离
 * ****/

#define CLAC_DIST(__A__, __B__) (sqrt((double)(__A__.x * __B__.x + __A__.y * __B__.y)))

// 直接计算最近点，不保存距离
double GetNearPoints(tsPoint P[], int PonitsNum) {
    double MinDist = MAX_DISTANCE;
    LOOP_ADD(iii, 0, PonitsNum) {
        LOOP_ADD(jjj, iii + 1, PonitsNum) {
            if(CLAC_DIST(P[iii], P[jjj]) < MinDist) {
                MinDist = CLAC_DIST(P[iii], P[jjj]);
            }
        }
    }
    return MinDist;
}

// 直接计算最近点
double GetNearPoints_saveNearPoints(tsPoint P[], int PonitsNum, tsPoint NearPoint[]) {
    double MinDist = MAX_DISTANCE;
    int NearPoint_Index[2] = {0};
    LOOP_ADD(iii, 0, PonitsNum) {
        LOOP_ADD(jjj, iii + 1, PonitsNum) {
            if(CLAC_DIST(P[iii], P[jjj]) < MinDist) {
                MinDist = CLAC_DIST(P[iii], P[jjj]);
                NearPoint_Index[0] = iii;
                NearPoint_Index[1] = jjj;
            }
        }
    }
    NearPoint[0] = P[NearPoint_Index[0]];
    NearPoint[1] = P[NearPoint_Index[1]];
    return MinDist;
}

// 节点数量小于此时不进入递归
#define MIN_POINT_NUM   8

// 分治算法求最近点递归函数
// 由于停止条件不好找，当节点数小于某个值时调用直接计算的函数
// 分： 首先分为PlQl/PrQr两部分，进入递归，返回最小距离Dl/Dr
// 治： delta等于距离最小值，删除Q中不在带内的点，计算Dc
double NearPoints_subDQ(tsPoint Psortx[], tsPoint Qsorty[], int PonitsNum) {
    if(PonitsNum < MIN_POINT_NUM) {
        // 这个步骤会改变P，先这么写看后面有没有影响
        return GetNearPoints(Psortx, PonitsNum);
    }
    

} 

// 使用分治算法计算最近点
// 这个实现没有保存最近点坐标，只保存了距离
double GetNearPoints_dq(tsPoint P[], int PonitsNum) {
    double MinDist = MAX_DISTANCE;
    // 获取排序点集
    tsPoint Psortx[PonitsNum], Qsorty[PonitsNum]; 
    memcpy(Psortx, P, PonitsNum*sizeof(tsPoint));
    memcpy(Qsorty, P, PonitsNum*sizeof(tsPoint));
    SortPoint_InsertionSort(Psortx, PonitsNum, GetPonit_x);
    SortPoint_InsertionSort(Qsorty, PonitsNum, GetPonit_y);

    return MinDist;
 }
