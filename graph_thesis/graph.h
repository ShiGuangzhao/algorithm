/*************************************************************************
    > File Name: graph.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 21时36分53秒
 ************************************************************************/

#ifndef _GRAPH_H_C
#define _GRAPH_H_C
#include "graph_init.h"
#include "../commom/common.h"
extern int giGraphNodeNum;

void topSort_simplify(tGraph G);
void topSort(tGraph G);
void PrintTopSort(tGraph G);

#endif /* GRAPH_H_C */
