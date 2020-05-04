/*************************************************************************
    > File Name: separate_chaining.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月03日 星期日 16时50分04秒
    > 内容: 散列表分离链接法的实现
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "separate_chaining.h"

pHashTable InitializeTable(int TableSize) {
    pHashTable table = (pHashTable)malloc(sizeof(struct HashTable));
    table->TableSize = TableSize;
    table->head = (pList *)malloc(sizeof(pList) * TableSize);
    for(int i = 0; i < TableSize; i++) {
        table->head[i] = NULL;
    }
    return table;
}

pListNode Find(const char *key, pHashTable H) {
    int index = Hash(key, H->TableSize);
    pList list = H->head[index];
    pListNode position = list; 
    while(position != NULL) {
        if(0 == strcmp(key, position->value)) {
            break;
        }
        position = position->next;
    }
    return position;
}

void Insert(const char *key, pHashTable H) {
    int index = Hash(key, H->TableSize);
    printf("index = %d\n", index);
    if(Find(key, H) == NULL) {
        pListNode temp = H->head[index];
        pListNode NewNode = (pListNode)malloc(sizeof(struct ListNode));
        memset(NewNode->value, '\0', 10);
        memcpy(NewNode->value,  key, strlen(key));
        if(temp != NULL)
            NewNode->next = temp->next;
        H->head[index] = NewNode;
    }
}

static void ListFree(pList L) {
    if(L) {
        ListFree(L->next);
        free(L);
    }
}

void Destory(pHashTable H) {
    for(int i = 0; i < H->TableSize; i++) {
        if(H->head[i]) {
            ListFree(H->head[i]);
        }
    }
    free(H->head);
    free(H);
}
