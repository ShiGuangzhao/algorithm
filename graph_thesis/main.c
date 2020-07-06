/*************************************************************************
    > File Name: main.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 22时18分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "../commom/common.h"

int giGraphNodeNum = 7;

tGraph ReadGraph(void) {
    tGraph G = GraphInit();
    AddEdge_Single(G, 0, 1);
    AddEdge_Single(G, 0, 2);
    AddEdge_Single(G, 0, 3);
    AddEdge_Single(G, 1, 3);
    AddEdge_Single(G, 1, 4);
    AddEdge_Single(G, 4, 3);
    AddEdge_Single(G, 4, 6);
    AddEdge_Single(G, 3, 6);
    AddEdge_Single(G, 3, 5);
    AddEdge_Single(G, 3, 2);
    AddEdge_Single(G, 2, 5);
    AddEdge_Single(G, 6, 5);
    return G;
}

int main(void) {
    tGraph G = ReadGraph();
    PrintTopSort(G);
    topSort(G);
    PrintTopSort(G);
    GraphDestory(G);
    return 0;
}
