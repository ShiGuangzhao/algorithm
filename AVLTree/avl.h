/*************************************************************************
    > File Name: avl.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2019年12月16日 星期一 11时19分27秒
 ************************************************************************/

#ifndef _AVL_H_C
#define _AVL_H_C
#include <stdlib.h>

typedef struct node{
    int data;
    int height;
    node *left;
    node *right;
} treeNode;

typedef treeNode* AVLTree;
typedef treeNode* AVLNode;

// 新建并初始化节点，返回节点
AVLNode newNode(int number);
// 根据数组初始化AVL，返回根节点指针
AVLTree init(int data[], int count);
// 在tree中查找，找到返回该节点，找不到返回NULL
AVLTree find(AVLTree tree, int number);
// 插入节点到树中，返回根节点指针
AVLTree insert (AVLTree tree, int number);
// 删除节点，返回根节点
AVLTree deletee (AVLTree tree, int number);
// 清空二叉树
void clear(AVLTree tree);


#endif /* AVL_H_C */
