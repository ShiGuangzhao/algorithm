/*************************************************************************
    > File Name: generalUF.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年06月20日 星期六 22时59分16秒
 ************************************************************************/

#include <stdio.h>
#include "generalUF.h"

void Initillize(DisjSet S) {
    for(int iii = 0; iii < NUM_SET; iii++) {
        S[iii] = 0;
    }
}

void SetUnion(DisjSet S, SetType S1, SetType S2) {
    S[S2] = S1;
}

SetType Find(ElemType X, DisjSet S) {
    while(S[X] != 0) {
        X = S[X];
    }
    return X;
}
