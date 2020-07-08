/*************************************************************************
    > File Name: queue.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 23时43分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../commom/common.h"

piQueue iQueueInit(int size) {
    piQueue Q = (piQueue)malloc(sizeof(iQueue));
    Q->data = (Queue_ElemType *)malloc(size* sizeof(Queue_ElemType));
    SET_ARRAY0_INT(Q->data, size)
    Q->size = size;
    Q->iHead = 0;
    Q->iNext = 0;
    return Q;
}

void iQueueDestory(piQueue Q) {
    if(Q) {
        free(Q->data);
        free(Q);
    }
}

static int QueueLeftSize(piQueue Q) {
    int iLeftSize = (Q->iHead + Q->size - Q->iNext) % Q->size;
    return iLeftSize;
}

/* ********
 * 入队
 * ****/
void iEnqueue(piQueue Q, Queue_ElemType value) {
    if(QueueLeftSize(Q) == 1) {
        PRINT_ERROR_EXIT("队列溢出，无法添加数据")
    }
    Q->data[Q->iNext++] = value;
    Q->iNext %= Q->size;
}

/* *********
 * 出队
 * ******/
Queue_ElemType iDequeue(piQueue Q) {
    if(Q->iNext == Q->iHead) {
        PRINT_ERROR_EXIT("队列空，无法弹出数据")
    }
    int value = Q->data[Q->iHead++];
    Q->iHead %= Q->size;
    return value;    
}

int iQueueIsEmpty(piQueue Q) {
    if(Q->iNext == Q->iHead) {
        return 1;
    }
    else {
        return 0;
    }
}
int iQueueIsFull(piQueue Q) {
    if(QueueLeftSize(Q) == 1) {
        return 1;
    }
    else {
        return 0;
    }
}
