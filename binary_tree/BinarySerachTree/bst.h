/*************************************************************************
    > File Name: bst.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年04月28日 星期二 16时13分01秒
 ************************************************************************/

#ifndef _BST_H_C
#define _BST_H_C
struct BSTreeNode;
typedef struct BSTreeNode * ptrToNode;
typedef ptrToNode BSTree;
typedef ptrToNode ptrToPosition;

/* ******
 * 清空树T，返回NULL
 * 如果当前节点为空则返回，否则MakeEmpty左右子树后free（T）
 * ** */
BSTree MakeEmpty(BSTree T);
/* ********
 * 插入元素X，返回root
 * 如果T NULL，新建节点返回
 * 如果T > X， 插入左子树，否则右子树，相同则报错
 * ****/
BSTree Insert(int X, BSTree T);
/* *******
 * 查找元素X，返回位置，否则返回NULL
 * 递归查找
 * 树为NULL则返回NULL
 * ****/
ptrToPosition Find(int X, BSTree T);
/* *******
 * 最大值，即树最右边的值可使用循环或递归
 * ****/
ptrToPosition FindMax(BSTree T);
/* **********
 * 最小值，即最左边的值
 * ********/
ptrToPosition FindMin(BSTree T);
/* *******
 * 删除节点X，返回树根(便于递归删除赋值)
 * 当删除节点只有一个儿子，直接用儿子代替
 * 如果有两个儿子，使用左子树最大值或右子树最小值代替
 * ******/
BSTree Delete(int X, BSTree T);

#endif /* BST_H_C */
