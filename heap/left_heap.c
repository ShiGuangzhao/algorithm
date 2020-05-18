/*************************************************************************
    > File Name: left_heap.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月09日 星期六 17时26分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

static pHeap Mergel(pHeap H1, pHeap H2) {
    // H1->value < H2->value
    if(H1->left == NULL) {  // H1为单节点，H1->npl不变
        H1->left = H2;
    }
    else {
        H1->right = Merge(H2, H1->right);   // 递归合并
        if(H1->left->npl < H1->right->npl) {// 左小于右则交换
            pNode temp = H1->right;
            H1->right = H1->left;
            H1->left = temp;
        }
        H1->npl = H1->right->npl + 1;       // 更新npl值
    }
    return H1;
}

pHeap Merge(pHeap H1, pHeap H2) {
    if(H1 == NULL) {
        return H2;
    }
    if(H2 == NULL) {
        return H1;
    }
    if(H1->value > H2->value) {
        return Mergel(H2, H1);
    }
    else {
        return Mergel(H1, H2);
    }
}

ValueType FindMin(pHeap H) {
    if(H == NULL) {
        printf("错误：NULL堆无法找到最小元素\n");
        exit(-1);
    }
    return H->value;
}

int IsEmpty(pHeap H) {
    if(H == NULL) {
        return true;
    }
    else {
        return false;
    }
}

pHeap Insertl(ValueType X, pHeap H) {
    pNode H2 = (pNode)malloc(sizeof(struct TreeNode));
    H2->value = X;
    H2->left = NULL;
    H2->right = NULL;
    H2->npl = 0;
    H = Merge(H, H2);
    return H;
}

pHeap DeleteMinl(pHeap H) {
    pHeap newHeap = Merge(H->left, H->right);
    free(H);
    return newHeap;
}

void Destory(pHeap H) {
    if(H != NULL) {
        Destory(H->left);
        Destory(H->right);
        free(H);
    }
}
