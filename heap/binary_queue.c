/*************************************************************************
    > File Name: binary_queue.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月17日 星期日 09时08分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_queue.h"

pBinQueue Initialize(void) {
    pBinQueue Q = (pBinQueue)malloc(sizeof(struct BinFrost));
    Q->size = 0;
    for(int iii = 0; iii < MAX_TREES; iii++) {
        Q->trees[iii] = NULL;
    }
    return Q;
}

ElemType FindMin(pBinQueue Q) {
    int iMinElem = 0;
    int iii = 0;
    if(Q == NULL || Q->size == 0) {
        printf("错误：寻找二项队列最小值时发现队列为空,返回0\n");
        return 0;
    }
    for(iii = 0; iii < MAX_TREES; iii++) {
        if(Q->trees[iii] != NULL) {
            iMinElem = Q->trees[iii]->value;
            break;
        }
    }
    for(; iii < MAX_TREES; iii++) {
        if(Q->trees[iii] != NULL && \
                Q->trees[iii]->value < iMinElem) {
            iMinElem = Q->trees[iii]->value;
        }
    }
    return iMinElem;
}

int IsEmpty(pBinQueue Q) {
    if(Q == NULL) {
        printf("错误：NULL队列无法判断是否为空\n");
        return true;
    }
    if(Q->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

int IsFull(pBinQueue Q) {
    if(Q == NULL) {
        printf("错误：NULL队列无法判断是否为满\n");
        return false;
    }
    if(Q->size == ((1 << MAX_TREES) - 1)) {
        return true;
    }
    else {
        return false;
    }
}

static void FreeTree(pBinTree T) {
    if(T != NULL) {
        FreeTree(T->nextBrother);
        FreeTree(T->leftChild);
        free(T);
    }
}

void MakeEmpty(pBinQueue Q) {
    if(Q != NULL) {
        for(int iii = 0; iii < MAX_TREES; iii++) {
            FreeTree(Q->trees[iii]);
        }
        free(Q);
    }
}

pBinTree CombineTrees(pBinTree T1, pBinTree T2) {
    if(T1->value < T2->value) {
        T2->nextBrother = T1->leftChild;
        T1->leftChild = T2;
        return T1;
    }
    else {
        T1->nextBrother = T2->leftChild;
        T2->leftChild = T1;
        return T2;
    }
}

ElemType DeletMin(pBinQueue Q) {
    int MinIndex = 0;
    int MinData = 0;
    int iii = 0;
    // 寻找具有最小根的树
    for(iii = 0; iii < MAX_TREES; iii++) {
        if(Q->trees[iii] != NULL) {
            MinIndex = iii;
        }
    }
    for(; iii < MAX_TREES; iii++) {
        if(Q->trees[iii] != NULL && \
                Q->trees[MinIndex]->value < Q->trees[iii]->value) {
            MinIndex = iii;
        }
    }
    MinData = Q->trees[MinIndex]->value;
    // 建立新树
    pBinQueue pNewQueue = Initialize();
    pNewQueue->size = (1 << MinIndex) - 1;
    pBinTree pTempTree = Q->trees[MinIndex]->leftChild;
    for(iii = MinIndex - 1; iii >= 0; iii--) {
        pNewQueue->trees[iii] = pTempTree;
        pTempTree = pTempTree->nextBrother;
        pNewQueue->trees[iii]->nextBrother = NULL;
    }
    // 删除最小根
    free(Q->trees[MinIndex]);
    Q->trees[MinIndex] = NULL;
    // 合并
    Q->size -= 1 << MinIndex;
    Q = Merge(Q, pNewQueue);
    return MinData;
}

/* **********
 * 合并到Q1并清空Q2
 * ****/
pBinQueue Merge(pBinQueue Q1, pBinQueue Q2) {
    Q1->size += Q2->size;
    pBinTree pTempTree = NULL;      // 上一次合并的结果
    for(int iii = 0; iii < MAX_TREES; iii++) {
        switch(!!Q1->trees[iii] + 2 * !!Q2->trees[iii] + \
                4 * !!pTempTree) {
            case 0:     // 都为NULL
            case 1:     // 只有Q1
                break;
            case 2:     // 只有Q2
                Q1->trees[iii] = Q2->trees[iii];
                Q2->trees[iii] = NULL;
                break;
            case 4:     // 只有temp
                Q1->trees[iii] = pTempTree;
                pTempTree = NULL;
                break;
            case 5:     // Q1+temp
                pTempTree = CombineTrees(pTempTree, Q1->trees[iii]);
                Q1->trees[iii] = NULL;
                break;
            case 6:     // Q2+temp
                pTempTree = CombineTrees(pTempTree, Q2->trees[iii]);
                Q2->trees[iii] = NULL;
                break;
            case 7:     // Q1+Q2+temp
                pTempTree = CombineTrees(pTempTree, Q2->trees[iii]);
                Q2->trees[iii] = NULL;
                break;
        }
    }
    free(Q2);
    return Q1;
}

void Insert(ElemType X, pBinQueue Q) {
    pBinQueue SingleNodeQueue = Initialize();
    SingleNodeQueue->size = 1;
    pNode NewNode = (pNode)malloc(sizeof(struct BinNode));
    NewNode->value = X;
    NewNode->leftChild = NULL;
    NewNode->nextBrother = NULL;
    SingleNodeQueue->trees[0] = NewNode;
    Q = Merge(Q, SingleNodeQueue);
}
