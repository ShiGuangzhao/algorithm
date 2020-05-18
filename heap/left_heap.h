/*************************************************************************
    > File Name: left_heap.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月09日 星期六 17时17分50秒
 ************************************************************************/

#ifndef _LEFT_HEAP_H_C
#define _LEFT_HEAP_H_C
typedef int ValueType;
struct TreeNode;
typedef struct TreeNode *pHeap;
typedef struct TreeNode *pNode;

pHeap Initialize(void);
ValueType FindMin(pHeap H);
int IsEmpty(pHeap H);
pHeap Merge(pHeap H1, pHeap H2);    // 合并操作
void Destory(pHeap H);

#define Insert(X, H)    (H = Insert1((X), H))   // 直接改变H
#define DeleteMin(H)    FindMin(H); H = DeleteMinl(H)// 返回删除的最小值
pHeap Insertl(ValueType X, pHeap H);
pHeap DeleteMinl(pHeap H);

struct TreeNode {
    ValueType value;
    pNode left;
    pNode right;
    int npl;    // 零路径长
};
#endif /* LEFT_HEAP_H_C */
