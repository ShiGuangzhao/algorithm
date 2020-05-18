/*************************************************************************
    > File Name: binary_queue.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月16日 星期六 21时04分47秒
 ************************************************************************/

#ifndef _BINARY_QUEUE_H_C
#define _BINARY_QUEUE_H_C

#define MAX_TREES   30

typedef int ElemType;
typedef struct BinNode *pNode;
typedef struct BinNode *pBinTree;
typedef struct BinFrost *pBinQueue;

struct BinNode {        // 二项树
    ElemType value;
    pNode leftChild;    // 左儿子
    pNode nextBrother;  // 下一个兄弟
};

struct BinFrost {       // 森林，二项树集合
    int size;
    pBinTree trees[MAX_TREES];
};

/* 初始化，申请内存并把数组元素设为NULL */
pBinQueue Initialize(void);
/* 删除最小元素并返回该元素 */
ElemType DeletMin(pBinQueue Q);
void MakeEmpty(pBinQueue Q);
/* 合并到Q1并清空Q2，返回Q1 */
pBinQueue Merge(pBinQueue Q1, pBinQueue Q2);
/* 初始化一棵单节点树并与Q合并 */
void Insert(ElemType X, pBinQueue Q);
ElemType FindMin(pBinQueue Q);
int IsEmpty(pBinQueue Q);
int IsFull(pBinQueue Q);
/* 合并两棵树 */
pBinTree CombineTrees(pBinTree T1, pBinTree T2);

#endif /* BINARY_QUEUE_H_C */
