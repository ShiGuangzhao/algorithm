/*************************************************************************
    > File Name: left_heap.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月09日 星期六 17时26分20秒
 ************************************************************************/

#include <stdio.h>
#include "left_heap.h"

static int GetNpl(pNode N) {
    if(N == NULL) {
        return -1;
    }
    return N->npl;
}

static void SetNpl(pNode N) {
    if(N == NULL) {
        printf("错误：无法为NULL节点设置NPL\n");
        return;
    }
    N->npl = GetNpl(N->left) < GetNpl(N->right)? \
             GetNpl(N->left) + 1: GetNpl(N->right) + 1;
}

pHeap Initialize(void) {
    return NULL;
}

pHeap Merge(pHeap H1, pHeap H2) {
    if(H1 == NULL) {
        return H2;
    }
    if(H2 == NULL) {
        return H1;
    }
    if(H1->value > H2->value) {
        pNode temp = Merge(H1, H2->right);
        H2->right = H2->left;
        H2->left = temp;
        SetNpl(H2);
        return H2;
    }
    else {
        pNode temp = Merge(H2, H1->right);
        H1->right = H1->left;
        H1->left = temp;
        SetNpl(H1);
        return H1;
    }
}
ValueType FindMin(pHeap H);
int IsEmpty(pHeap H);
pHeap Insertl(ValueType X, pHeap H);
pHeap DeleteMinl(pHeap H);

