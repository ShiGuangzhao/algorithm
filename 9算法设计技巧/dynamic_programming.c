/*************************************************************************
    > File Name: dynamic_programming.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月20日 星期一 23时26分41秒
 ************************************************************************/

#include <stdio.h>
#include "../commom/common.h"
#include "dynamic_programming.h"

#define MAXIUM_M    0x7fffffff

/* **********
 * 矩阵相乘顺序安排
 * 输入：c[]为Ai的列数，c[0]为A1的行数，N为矩阵数量
 * 输出：M为(N+1)*(N+1)二维矩阵，存储路径的复杂度，LastChange存储最后改变
 * ******/
void OptMatrix(int c[], int N, pMatrix M, pMatrix LastChange) {
    int Left, Right, iii, jjj;
    tMatrixData M_iii;
    LOOP_ADD_Inited(Left, 0, N) {
        MATRIX_DATA(M, Left, Left) = 0;
    }
    LOOP_ADD_Inited(jjj, 0, N-1) {
        LOOP_ADD_Inited(Left, 0, N-jjj) {
            Right = Left + jjj;
            MATRIX_DATA(M, Left, Right) = MAXIUM_M;
            LOOP_ADD_Inited(iii, Left+1, Right-1) {
                M_iii = MATRIX_DATA(M, Left, iii) + \
                        MATRIX_DATA(M, iii + 1, Right) + \
                        c[Left]*c[iii+1]*c[Right+1];
                if(M_iii < MATRIX_DATA(M, Left, Right)) {
                    MATRIX_DATA(M, Left, Right) = M_iii;
                    MATRIX_DATA(LastChange, Left, Right) = iii;
                }
            }
        }
    } 
}
