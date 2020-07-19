/*************************************************************************
    > File Name: matrix.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月19日 星期日 16时50分43秒
 ************************************************************************/

#ifndef _MATRIX_H_C
#define _MATRIX_H_C
typedef int tMatrixData;
typedef tMatrixData *pData;

typedef struct {
    int SizeN;
    int SizeM;
    tMatrixData *data;
}   tsMatrix;
typedef tsMatrix *pMatrix;

#define MATRIX_DATA(__Mat__, __m__, __n__)  \
    (*((__Mat__)->data + (__m__)*(__Mat__)->SizeN + (__n__)))

// 初始化零矩阵
pMatrix MatrixInit_Zero(int m, int n);
// 初始化随机矩阵，直接调用rand函数，不做种子初始化
pMatrix MatrixInit_Rand(int m, int n, int range = 10);
// 删除矩阵
void MatrixDestory(pMatrix M);
// 打印矩阵
void PrintMatrix(pMatrix M);

// 直接根据定义计算C=AB
void MatrixMultiply(pMatrix A, pMatrix B, pMatrix C);

#endif /* MATRIX_H_C */
