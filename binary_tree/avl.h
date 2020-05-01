/*************************************************************************
    > File Name: avl.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年04月30日 星期四 10时40分07秒
 ************************************************************************/

#ifndef _AVL_H_C
#define _AVL_H_C
struct AVLTreeNode;
typedef struct AVLTreeNode * ptrToNode;
typedef ptrToNode AVLTree;
typedef ptrToNode ptrToPosition;

/* ******
 * 清空树T，返回NULL
 * 如果当前节点为空则返回，否则MakeEmpty左右子树后free（T）
 * ** */
AVLTree MakeEmpty(AVLTree T);
/* ********
 * 插入元素X，返回root， 如果T NULL，新建节点返回
 * 如果T > X， 插入左子树，否则右子树，相同则报错
 * 返回过程比较高度，高度不对则旋转
 * ****/
AVLTree Insert(int X, AVLTree T);
/* *******
 * 查找元素X，返回位置，否则返回NULL
 * 递归查找，树为NULL则返回NULL
 * ****/
ptrToPosition Find(int X, AVLTree T);
/* *******
 * 最大值，即树最右边的值可使用循环或递归
 * ****/
ptrToPosition FindMax(AVLTree T);
/* **********
 * 最小值，即最左边的值
 * ********/
ptrToPosition FindMin(AVLTree T);
/* *******
 * 删除节点X，返回树根(便于递归删除赋值)
 * 当删除节点只有一个儿子，直接用儿子代替
 * 如果有两个儿子，使用左子树最大值或右子树最小值代替
 * ******/
AVLTree Delete(int X, AVLTree T);
#endif /* AVL_H_C */
