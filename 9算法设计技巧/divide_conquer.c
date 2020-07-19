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
 * P为输入点集，PointsNum为点集中的点数，NearPoint为最近的两个点
 * 返回值为最短距离
 * ****/

#define CLAC_DIST(__A__, __B__) \
    (sqrt((double)((__A__.x - __B__.x) * (__A__.x - __B__.x) + (__A__.y - __B__.y) * (__A__.y - __B__.y))))
#define CLAC_DIST_Y(__A__, __B__) \
    ((__A__).y > (__B__).y? (__A__).y - (__B__).y: (__B__).y - (__A__).y)

// 直接计算最近点，不保存距离
double GetNearPoints(tsPoint P[], int PointsNum) {
    double MinDist = MAX_DISTANCE;
    LOOP_ADD(iii, 0, PointsNum) {
        LOOP_ADD(jjj, iii + 1, PointsNum) {
            if(CLAC_DIST(P[iii], P[jjj]) < MinDist) {
                MinDist = CLAC_DIST(P[iii], P[jjj]);
            }
        }
    }
    return MinDist;
}

// 直接计算最近点
double GetNearPoints_saveNearPoints(tsPoint P[], int PointsNum, tsPoint NearPoint[]) {
    double MinDist = MAX_DISTANCE;
    int NearPoint_Index[2] = {0};
    LOOP_ADD(iii, 0, PointsNum) {
        LOOP_ADD(jjj, iii + 1, PointsNum) {
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

static void ReadQindex_ToQlr(int QyIndex[], int Qlr[], int PointsNum, int LeftPointsNum) {
    int *Ql = Qlr;
    int *Qr = Qlr + LeftPointsNum;
    LOOP_ADD(iii, 0, PointsNum) {
        if(QyIndex[iii] < LeftPointsNum) {
            *Ql = QyIndex[iii];
            Ql++;
        }
        else {
            *Qr = QyIndex[iii] - LeftPointsNum;
            Qr++;
        }
    }
}

static void ClacMinDcInStrip(tsPoint Psortx[], int QyIndex[], int Qlr[], int LeftPointsNum, int PointsNum, double *dC, tsPoint NearPoint[]) {
    // 找出带内的点，扫描Q是因为要保持按y排序
    int iii = 0, jjj = 0;
    int NumPointsInStrip = 0;
    int xTemp = 0;
    double MiddleX = (Psortx[LeftPointsNum].x + Psortx[LeftPointsNum - 1].x) / 2;
    LOOP_ADD_Inited(iii, 0, PointsNum) {
        xTemp = Psortx[QyIndex[iii]].x;
        if(xTemp > MiddleX - *dC && xTemp < MiddleX + *dC) {
            Qlr[NumPointsInStrip++] = QyIndex[iii];
        }
    }
    // 计算dC
    LOOP_ADD_Inited(iii, 0, NumPointsInStrip) {
        LOOP_ADD_Inited(jjj, iii + 1, NumPointsInStrip) {
            if(CLAC_DIST_Y(Psortx[Qlr[iii]], Psortx[Qlr[jjj]]) > *dC) {
                break;
            }
            if(CLAC_DIST(Psortx[Qlr[iii]], Psortx[Qlr[jjj]]) < *dC) {
                *dC = CLAC_DIST(Psortx[Qlr[iii]], Psortx[Qlr[jjj]]);
                NearPoint[0] = Psortx[Qlr[iii]];
                NearPoint[1] = Psortx[Qlr[jjj]];
            }
        }
    }
}

// 分治算法求最近点递归函数
// 由于停止条件不好找，当节点数小于某个值时调用直接计算的函数
// 分： 首先分为PlQl/PrQr两部分，进入递归，返回最小距离Dl/Dr
// 治： delta等于距离最小值，删除Q中不在带内的点，计算Dc
static double NearPoints_subDQ(tsPoint Psortx[], int QyIndex[], int PointsNum, tsPoint NearPoint[]) {
    double dL = 0, dR = 0, dC = 0;
    int LeftPointsNum = PointsNum / 2;
    tsPoint NearPoint_R[2];
    // 用于存放Ql, Qr
    int Qlr[PointsNum];
    // 点数过小时结束递归
    if(PointsNum < MIN_POINT_NUM) {
        return GetNearPoints_saveNearPoints(Psortx, PointsNum, NearPoint);
    }
    // P直接通过索引划分，Q需要扫描
    ReadQindex_ToQlr(QyIndex, Qlr, PointsNum, LeftPointsNum);
    // 递归
    dL = NearPoints_subDQ(Psortx, Qlr, LeftPointsNum, NearPoint);
    dR = NearPoints_subDQ(Psortx + LeftPointsNum, Qlr + LeftPointsNum, PointsNum - LeftPointsNum, NearPoint_R);
    // 计算dC
    if(dL > dR) {
        dC = dR;
        NearPoint[0] = NearPoint_R[0];
        NearPoint[1] = NearPoint_R[1];
    }
    else {
        dC = dL;
    }
    // 寻找带内点并计算dC
    ClacMinDcInStrip(Psortx, QyIndex, Qlr, LeftPointsNum, PointsNum, &dC, NearPoint);
    return dC;
} 

// 使用分治算法计算最近点
// 这个实现没有保存最近点坐标，只保存了距离
double GetNearPoints_dq_saveNearPoints(tsPoint P[], int PointsNum, tsPoint NearPoint[]) {
    // 获取排序点集
    tsPoint Psortx[PointsNum], Qsorty[PointsNum]; 
    int QyIndex[PointsNum];
    memcpy(Psortx, P, PointsNum*sizeof(tsPoint));
    SortPoint_InsertionSort(Psortx, PointsNum, GetPoint_x);
    memcpy(Qsorty, Psortx, PointsNum*sizeof(tsPoint));
    SortPointIndex_InsertionSort(Qsorty, PointsNum, GetPoint_y, QyIndex);
    // 分治
    return NearPoints_subDQ(Psortx, QyIndex, PointsNum, NearPoint);
}
