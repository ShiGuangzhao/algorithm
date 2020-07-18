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

/* ******
 * 最近点问题
 * ***/
#define MAX_DISTANCE    (0x7fffffff)
typedef int tPointType;
typedef struct {
    tPointType x;
    tPointType y;
}   tsPoint;
typedef tsPoint* pPoint;

// 直接计算最近点
double GetNearPoints(tsPoint P[], int PonitsNum);
double GetNearPoints_saveNearPoints(tsPoint P[], int PonitsNum, tsPoint NearPoint[]);
// 使用分治算法计算最近点
double GetNearPoints_dq(tsPoint P[], int PonitsNum);
// double GetNearPoints_dq(tsPoint P[], int PonitsNum, tsPoint NearPoint[]);
extern void SortPoint_InsertionSort(tsPoint A[], int PonitsNum, int (*key)(tsPoint p));
// extern void SortPoint_InsertionSort(tsPoint A[], int PonitsNum, int (*key)(tsPoint p), int sort_result);
extern void PrintPoints(tsPoint P[], int NodeNum);
extern int GetPonit_x(tsPoint p);
extern int GetPonit_y(tsPoint p);

#endif /* DIVIDE_CONQUER_H_C */
