/*************************************************************************
    > File Name: bst.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年04月28日 星期二 16时02分10秒
    > 二叉查找树的实现
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* 二叉搜索树节点定义 */
struct BSTreeNode {
    int value;
    BSTree left;
    BSTree right;
};

BSTree MakeEmpty(BSTree T) {
    if(T != NULL) {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;    
}

BSTree Insert(int X, BSTree T) {
    if(T == NULL) {
        ptrToNode tempNode = (ptrToNode)malloc(sizeof(struct BSTreeNode));
        tempNode->value = X;
        tempNode->left = NULL;
        tempNode->right = NULL;
        T = tempNode;
    }
    else if(T->value == X) {
        printf("错误：不允许插入相同值");
        exit(-1);
    }
    else if(T->value > X) {
        T->left = Insert(X, T->left);
    }
    else{
        T->right = Insert(X, T->right);
    }
    return T;
}

ptrToPosition Find(int X, BSTree T) {
    ptrToNode tempNode;
    if(NULL == T || T->value == X) {
        tempNode = T;
    }
    else if(T->value > X) {
        tempNode = Find(X, T->left);
    }
    else {
        tempNode = Find(X, T->right);
    }
    return tempNode;
}

ptrToPosition FindMax(BSTree T) {
    if(T == NULL) {
        return NULL;
    }
    ptrToNode tempNode = T;
    while(tempNode->right != NULL) {
        tempNode = tempNode->right;
    }
    return tempNode;
}

ptrToPosition FindMin(BSTree T) {
    if(T == NULL) {
        return NULL;
    }
    ptrToNode tempNode = T;
    while(tempNode->left != NULL) {
        tempNode = tempNode->left;
    }
    return tempNode;
}

/* ********
 * 删除树的最小元素，配合Delete函数使用
 * 返回最小元素
 * ******/
static BSTree DeleteMin(BSTree T) {
    ptrToNode oldT = T;
    if(T == NULL) {
        printf("错误，在空树中删除最小值");
        exit(-1);
    }
    while(T->left) {
        oldT = T;
        T = T->left;
    }
    ptrToNode tempNode = T;
    if(T->right) {
        T->value = T->right->value;
        free(T->right);
    }
    else {
        free(T);
        oldT->left = NULL;
    }
    return tempNode;
}

BSTree Delete(int X, BSTree T) {
    if(NULL == T) {
        return T;
    }
    if(T->value == X) {
        if(T->left && T->right) {
            T->value = DeleteMin(T->right)->value;
        }
        else {
            ptrToNode tempNode = T;
            if(T->left) {
                T = T->left;
            }
            else {
                T = T->right;
            }
            free(tempNode);
        }
    }
    else if(T->value > X) {
        T->left = Delete(X, T->left);
    }
    else {
        T->right = Delete(X, T->right);
    }
    return T;
}


