/*************************************************************************
    > File Name: queue.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月05日 星期日 23时43分56秒
 ************************************************************************/

#ifndef _QUEUE_H_C
#define _QUEUE_H_C
typedef int Queue_ElemType;
typedef struct iQueue_Struct {
    Queue_ElemType *data;
    int size;
    int iHead;
    int iNext;
} iQueue;
typedef iQueue *piQueue;

piQueue iQueueInit(int size);
void iQueueDestory(piQueue Q);
void iEnqueue(piQueue Q, Queue_ElemType value);
Queue_ElemType iDequeue(piQueue Q);
int iQueueIsEmpty(piQueue Q);
int iQueueIsFull(piQueue Q);
#endif /* QUEUE_H_C */
