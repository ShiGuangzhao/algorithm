/*************************************************************************
    > File Name: graph_init.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月04日 星期六 17时54分23秒
 ************************************************************************/

/* **********
 * 针对顶点名称为0, 1, 2, ...的情况初始化图
 * ******/
#include <stdio.h>
#include <stdlib.h>
#include "graph_init.h"

tGraph GraphInit(void) {
    tGraph G = (tGraph)malloc(sizeof(tsListNode) * MAX_NODE_NUM);
    for(int iii = 0; iii < MAX_NODE_NUM; iii++) {
        G[iii].next = NULL;
        G[iii].name = NODE_INIT_VALUE;
        G[iii].weight = NODE_INIT_WEIGHT;
    }
    return G;
}

void FreeList(tiGraphList list) {
    if(list != NULL) {
        if(list->next != NULL) {
            FreeList(list->next);
        }
        free(list);
    }
}

void GraphDestory(tGraph G) {
    if(G != NULL) {
        for(int iii = 0; iii < MAX_NODE_NUM; iii++) {
            FreeList(G[iii].next);
        }
        free(G);
    }
}

void AddEdge_Single(tGraph G, Node U, Node V, WeightType weight) {
    tiGraphList list = &(G[U]);
    while(list->next != NULL) {
        if(list->next->name == V) {
            return;
        }
        list = list->next;
    }
    list->next = (pListNode)malloc(sizeof(tsListNode));
    list = list->next;
    list->name = V;
    list->weight = weight;
    list->next = NULL;
}

void AddEdge_Double(tGraph G, Node U, Node V, WeightType weight) {
    AddEdge_Single(G, U, V, weight);
    AddEdge_Single(G, V, U, weight);
}

void DeleteEdge_Single(tGraph G, Node U, Node V) {
    tiGraphList list = &(G[U]);
    pListNode tempNode = NULL;
    while(list->next != NULL) {
        if(list->next->name == V) {
            tempNode = list->next;
            list->next = list->next->next;
            free(tempNode);
        }
        list = list->next;
    }
}

void DeleteEdge_Double(tGraph G, Node U, Node V) {
    DeleteEdge_Single(G, U, V);
    DeleteEdge_Single(G, V, U);
}

