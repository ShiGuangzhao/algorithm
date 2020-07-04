/*************************************************************************
    > File Name: graph_init.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月04日 星期六 18时52分18秒
 ************************************************************************/

#ifndef _GRAPH_INIT_H_C
#define _GRAPH_INIT_H_C
#define MAX_NODE_NUM    20

typedef int     Node;
struct ListNode;
typedef struct ListNode {
    Node name;
    struct ListNode *next;
} tsListNode;
// 邻接表表示方法链表指针
typedef tsListNode* tiGraphList;
typedef tsListNode* pListNode;
// 邻接表表示方法图指针
typedef tiGraphList tiListGraph;
// 邻接矩阵表示法
// typedef int tiMatrixGraph[MAX_NODE_NUM][MAX_NODE_NUM];
// 默认使用邻接表方法
typedef tiListGraph tGraph;

// 以下方法基于邻接表方法实现
tGraph GraphInit(void);
void GraphDestory(tGraph G);
void AddEdge_Single(tGraph G, Node U, Node V);
void AddEdge_Double(tGraph G, Node U, Node V);
void DeleteEdge_Single(tGraph G, Node U, Node V);
void DeleteEdge_Double(tGraph G, Node U, Node V);

#endif /* GRAPH_INIT_H_C */
