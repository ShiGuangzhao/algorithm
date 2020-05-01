/*************************************************************************
    > File Name: avl.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年04月29日 20:11:06
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct AVLTreeNode {
    int value;
    AVLTree left;
    AVLTree right;
    int height;
};

static int Height(ptrToNode N) {
    if(N == NULL) {
        return -1;
    }
    else {
        return N->height;
    }
}

static void SetHeight(ptrToNode N) {
    N->height = Height(N->left) > Height(N->right)? \
                Height(N->left) + 1 : Height(N->right) + 1;
}

AVLTree Insert(int X, AVLTree T) {
    if(T == NULL) {
        ptrToNode tempNode = (ptrToNode)malloc(sizeof(struct AVLTreeNode));
        tempNode->value = X;
        tempNode->left = NULL;
        tempNode->right = NULL;
        /* tempNode->height = 0;   // 树叶高度为0 */
        T = tempNode;
    }
    else if(T->value == X) {
        printf("错误，程序不允许重复插入一个值");
        exit(-1);
    }
    else if(T->value > X) {
        T->left = Insert(X, T->left);
        if(Height(T->left) - Height(T->right) == 2) {   // 高度不平衡
            if(X < T->left->value) {    // 左左插入
                ptrToNode k1 = T->left;
                T->left = k1->right;
                SetHeight(T);
                k1->right = T;
                T = k1;
            }
            else {  // 左右插入
                ptrToNode k1 = T->left;
                ptrToNode k2 = k1->right;
                T->left = k2->right;
                SetHeight(T);
                k1->right = k2->left;
                SetHeight(k1);
                k2->left = k1;
                k2->right = T;
                T = k2;
            }
        }
    }
    else {
        T->right = Insert(X, T->right);
        if(Height(T->right) - Height(T->left) == 2) {
            if(X < T->right->value) {   // 右左插入
                ptrToNode k3 = T->right;
                ptrToNode k2 = k3->left;
                T->right = k2->left;
                SetHeight(T);
                k3->left = k2->right;
                SetHeight(k3);
                k2->left = T;
                k2->right = k3;
                T = k2;
            }
            else{   // 右右插入
                ptrToNode k2 = T->right;
                T->right = k2->left;
                SetHeight(T);
                k2->left = T;
                T = k2;
            }
        }
    }
    SetHeight(T);
    return T;
}


AVLTree MakeEmpty(AVLTree T) {
    if(T != NULL) {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;    
}

ptrToPosition Find(int X, AVLTree T) {
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

ptrToPosition FindMax(AVLTree T) {
    if(T == NULL) {
        return NULL;
    }
    ptrToNode tempNode = T;
    while(tempNode->right != NULL) {
        tempNode = tempNode->right;
    }
    return tempNode;
}

ptrToPosition FindMin(AVLTree T) {
    if(T == NULL) {
        return NULL;
    }
    ptrToNode tempNode = T;
    while(tempNode->left != NULL) {
        tempNode = tempNode->left;
    }
    return tempNode;
}

AVLTree Delete(int X, AVLTree T);
