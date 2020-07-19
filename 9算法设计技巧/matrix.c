/*************************************************************************
    > File Name: matrix.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月19日 星期日 16时53分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "../commom/common.h"

// 初始化零矩阵
pMatrix MatrixInit_Zero(int m, int n) {
    pMatrix Mat = (pMatrix)malloc(sizeof(tsMatrix));
    Mat->data = (pData)malloc(sizeof(tMatrixData)*m*n);
    memset(Mat->data, 0, sizeof(tMatrixData)*m*n);
    Mat->SizeM = m;
    Mat->SizeN = n;
    return Mat;
}

// 初始化随机矩阵，直接调用rand函数，不做种子初始化
pMatrix MatrixInit_Rand(int m, int n, int range) {
    pMatrix Mat = (pMatrix)malloc(sizeof(tsMatrix));
    Mat->data = (pData)malloc(sizeof(tMatrixData)*m*n);
    memset(Mat->data, 0, sizeof(tMatrixData)*m*n);
    Mat->SizeM = m;
    Mat->SizeN = n;
    LOOP_ADD(iii, 0, m) {
        LOOP_ADD(jjj, 0, n) {
            MATRIX_DATA(Mat, iii, jjj) = rand()%range;
        }
    }
    return Mat;
}

// 删除矩阵
void MatrixDestory(pMatrix M) {
    if(M) {
        if(M->data) {
            free(M->data);
        }
        free(M);
    }
}

// 打印矩阵
void PrintMatrix(pMatrix M) {
    if(M) {
        printf("------------------------------------\n");
        LOOP_ADD(m, 0, M->SizeM) {
            LOOP_ADD(n, 0, M->SizeN) {
                printf("%d\t", MATRIX_DATA(M, m, n));
            }
            printf("\n");
        }
        printf("------------------------------------\n");
        
    }
    else {
        PRINT_WARRING("矩阵为空，无法打印");
    }
}


/* ************
 * 分治算法用于降低矩阵乘法复杂度
 * ******/
static void CheckMultMatrix(pMatrix A, pMatrix B, pMatrix C) {
    if(A == NULL || B == NULL || C == NULL) {
        PRINT_ERROR_EXIT("矩阵为空，无法相乘");
    }
    else if(A->SizeN != B->SizeM || A->SizeM != C->SizeM || B->SizeN != C->SizeN) {
        PRINT_ERROR_EXIT("矩阵维度错误，无法相乘");
    }
}

// 直接根据定义计算C=AB
void MatrixMultiply(pMatrix A, pMatrix B, pMatrix C) {
    CheckMultMatrix(A, B, C);
    int Cm, Cn, iii;
    tMatrixData tempData = 0;
    LOOP_ADD_Inited(Cm, 0, C->SizeM) {
        LOOP_ADD_Inited(Cn, 0, C->SizeN) {
            tempData = 0;
            LOOP_ADD_Inited(iii, 0, A->SizeN) {
                tempData += MATRIX_DATA(A, Cm, iii) * MATRIX_DATA(B, iii, Cn);
            }
            MATRIX_DATA(C, Cm, Cn) = tempData;
        }
    }
}

