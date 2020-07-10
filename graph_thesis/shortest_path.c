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
void ShortestPath_noWeight_simplify(tGraph G, int viPv[], Node startV) {
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
void ShortestPath_noWeight(tGraph G, int viPv[], Node startV) {
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


/* *********
 * 寻找位置且d_v最小的点
 * *****/
Node Get_SmallestUnknowNode(tGraph G, int viKnown[]) {
    Node iSmallNode = -1;
    int iii = 0;
    for(; iii < tiGraphList; iii++) {
        if(viKnown[iii] == 0 && G[iii].name != NODE_INIT_VALUE) {
            iSmallNode = iii;
            break;
        }
    }
    for(; iii < tiGraphList; iii++) {
        if(viKnown[iii] == 0 \
                && G[iii].name != NODE_INIT_VALUE \
                && G[iii].name < G[iSmallNode].name) {
            iSmallNode = iii;
        }
    }
    return iSmallNode;
}


/* ************
 * 无负权单源赋权最短路径计算
 * Dijkstra算法：每次选取最小未知点进行更新
 * *******/
void ShortestPath_PassiveWeight(tGraph G, int viPv[], Node startV) {
    int viKnown[giGraphNodeNum] = {0};
    Node iSmallNode;
    Node iTempNode;
    tiGraphList list = NULL;
    viPv[startV] = startV;
    G[startV].name = 0;
    for(int iii = 0; iii < giGraphNodeNum; iii++) {
        // 获取最小值点
        if((iSmallNode = Get_SmallestUnknowNode(G, viKnown)) < 0) {
            PRINT_WARRING("运行Dijkstra算法时发现图中有不可到达的点");
            break;
        }
        viKnown[iSmallNode] = 1;
        // 更正邻接节点
        list = G[iSmallNode].next;
        while(list != NULL) {
            iTempNode = list->name;
            if(G[iTempNode].name == NODE_INIT_VALUE \
                    || G[iTempNode].name > G[iSmallNode].name + list->weight) {
                G[iTempNode].name = G[iSmallNode].name + list->weight;
                viPv[iTempNode] = iSmallNode;
            }
        }
    }
}
