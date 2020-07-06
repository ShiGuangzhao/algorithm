/*************************************************************************
    > File Name: topSort.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 21时37分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "../queue/queue.h"

/* ***********
 * 计算图各个点的入度
 * 要求输入iInDegree初始值为0
 * ******/
void clacGraphInDegree(tGraph G, int iInDegree[]) {
    tiGraphList list = NULL;
    SET_ARRAY0_INT(iInDegree, giGraphNodeNum)
    for(int iii = 0; iii < giGraphNodeNum; iii++) {
        list = G[iii].next;
        while(list != NULL) {
            iInDegree[list->name]++;
            list = list->next;
        }
    }
}

/* *********
 * 寻找入度为0的节点
 * ******/
Node findNodeInDegree0(tGraph G, int iInDegree[]) {
    for(int iii = 0; iii < giGraphNodeNum; iii++) {
        if(iInDegree[iii] == 0 && G[iii].name == NODE_INIT_VALUE) {
            return iii;
        }
    }
    return -1;
}

/* *******
 * 简单拓扑排序，复杂度为二次
 * 输出拓扑编号存储在头结点中（所以初始值最好为负数）
 * *****/
void topSort_simplify(tGraph G) {
    int iInDegree[giGraphNodeNum];
    int iNodeIn0 = -1;
    tiGraphList list = NULL;
    // 计算入度
    clacGraphInDegree(G, iInDegree);
    for(int iii = 0; iii < giGraphNodeNum; iii++) {
        // 寻找入度为0的点
        iNodeIn0 = findNodeInDegree0(G, iInDegree);
        if(iNodeIn0 >= 0) {
            G[iNodeIn0].name  = iii;
            list = G[iNodeIn0].next;
            while(list != NULL) {
                iInDegree[list->name]--;
                list = list->next;
            }
        }
        else {
            PRINT_ERROR_EXIT("找不到入度为零的点");
        }
    }
}


#define QueueSize_topSort   5

/* ************
 * 好一点的拓扑排序方式
 * *****/
void topSort(tGraph G) {
    int iInDegree[giGraphNodeNum];
    int iNodeIn0 = -1;
    tiGraphList list = NULL;
    int iii = 0;
    // 队列
    piQueue queue = iQueueInit(QueueSize_topSort);
    // 计算入度
    clacGraphInDegree(G, iInDegree);
    for(iii = 0; iii < giGraphNodeNum; iii++) {
        if(iInDegree[iii] == 0 && G[iii].name == NODE_INIT_VALUE) {
            iEnqueue(queue, iii);
        }
    }
    for(iii = 0; iii <giGraphNodeNum; iii++) {
        iNodeIn0 = iDequeue(queue);
        G[iNodeIn0].name = iii;
        list = G[iNodeIn0].next;
        while(list != NULL) {
            if((--iInDegree[list->name]) == 0) {
                iEnqueue(queue, list->name);
            }
            list = list->next;
        }
    }
    iQueueDestory(queue);
}

/* ***********
 * 拓扑顺序存储在头节点中，打印拓扑顺序
 * *******/
void PrintTopSort(tGraph G) {
    printf("开始打印拓扑顺序\n");
    printf("---------------------------------------\n");
    for(int iii = 0; iii < giGraphNodeNum; iii++) {
        printf("Node: %d, Rank: %d\n", iii + 1, G[iii].name);
    }
    printf("---------------------------------------\n");
}
