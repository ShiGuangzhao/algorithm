/*************************************************************************
    > File Name: divide_conquer.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月17日 星期五 11时55分53秒
 ************************************************************************/

#ifndef _DIVIDE_CONQUER_H_C
#define _DIVIDE_CONQUER_H_C
/* **********
 * 分治算法程序
 * *******/

/* **********
 * 最近点问题
 * ***/
typedef int tPointType;
typedef struct {
    tPointType x;
    tPointType y;
}   tsPinot;
typedef tsPinot* pPinot;
// 直接计算最近点
tPointType GetNearPoints(tsPinot P[], int PonitsNum, tsPinot NearPoint[]);
// 使用分治算法计算最近点
tPointType GetNearPoints_dq(tsPinot P[], int PonitsNum, tsPinot NearPoint[]);



#endif /* DIVIDE_CONQUER_H_C */
