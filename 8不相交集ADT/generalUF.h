/*************************************************************************
    > File Name: generalUF.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年06月20日 星期六 22时32分45秒
    > 基本的不相交集ADT，数组元素为0, 1, 2, ...
 ************************************************************************/

#ifndef _GENERALUF_H_C
#define _GENERALUF_H_C
#define NUM_SET     20
typedef int DisjSet[NUM_SET];
typedef int SetType;
typedef int ElemType;

void Initillize(DisjSet S);
void SetUnion(DisjSet S, SetType S1, SetType S2);
SetType Find(ElemType X, DisjSet S);

#endif /* GENERALUF_H_C */
