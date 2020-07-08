/*************************************************************************
    > File Name: shortest_path.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月08日 星期三 10时28分45秒
 ************************************************************************/

#include <stdio.h>
#include "graph.h"
#include "../queue/queue.h"

/* **********
 * 广度优先搜索算法求最短路径算法
 * 这个函数未优化，复杂度为二次
 * ******/
void ShortestPath_noWeight_simplify(tGraph G, int viPv[], Node startV = 3) {
    int viKnown[giGraphNodeNum] = {0};
    int current_d, id;
    Node tempNode;
    tiGraphList list = NULL;
    G[startV].name = 0;
    viPv[startV] = startV;
    for(current_d = 0; current_d < giGraphNodeNum; current_d++) {
        for(id = 0; id < giGraphNodeNum; id++) {
            if(viKnown[id] == 0 && G[id].name == current_d) {
                list = G[id].next;
                while(list != NULL) {
                    tempNode = list->name;
                    if(G[tempNode].name == NODE_INIT_VALUE) {
                        G[tempNode].name = current_d + 1;
                        viPv[tempNode] = id;
                    }
                    list = list->next;
                }
            }
        }
    }
}

#define QueueSize_shortestPath  5

/* **********
 * 广度优先搜索算法求最短路径算法
 * 这个函数使用队列优化，复杂度为E+V
 * ******/
void ShortestPath_noWeight(tGraph G, int viPv[], Node startV = 3) {
    Node tempNode, tempListNode;
    tiGraphList list = NULL;
    // 队列
    piQueue queue = iQueueInit(QueueSize_shortestPath);
    // 初始化
    G[startV].name = 0;
    viPv[startV] = startV;
    iEnqueue(queue, startV);
    while(!iQueueIsEmpty(queue)) {
        tempNode = iDequeue(queue);
        list = G[tempNode].next;
        while(list != NULL) {
            tempListNode = list->name;
            if(G[tempListNode].name == NODE_INIT_VALUE) {
                G[tempListNode].name = G[tempNode].name + 1;
                viPv[tempListNode] = tempNode;
                iEnqueue(queue, tempListNode);
            }
            list = list->next;
        }
    }
    iQueueDestory(queue);
}
