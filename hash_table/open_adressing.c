/*************************************************************************
    > File Name: open_adressing.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月04日 星期一 13时23分46秒
    > 介绍：开放定址法--平方探测法散列表
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "open_adressing.h"

pHashTable InitializeTable(int TableSize) {
    pHashTable H = (pHashTable)malloc(sizeof(struct HashTable));
    H->TableSize = TableSize;
    H->table = (pHashNode)malloc(sizeof(struct HashNode) * TableSize);
    for(int i = 0; i < TableSize; i++) {
        H->table[i].state = Empty;
        memset(H->table[i].value, '\0', 10);
    }
    return H;
}

void Destory(pHashTable H) {
    if(H != NULL) {
        free(H->table);
        free(H);
    }
}

Index Find(ElemType key, pHashTable H) {
    Index index = Hash(key, H->TableSize);
    Index position = index;
    int i = 1;
    while(H->table[position].state != Empty && \
            strcmp(H->table[position].value, key) != 0) {
        position = index + i*i;
        i++;
        if(position > H->TableSize) {
            position -= H->TableSize;
        }
    }
    return position;
}

void Insert(ElemType key, pHashTable H) {
    Index position = Find(key, H);
    if(H->table[position].state == Used) {
        printf("重复插入元素:%s，取消插入", key);
    }
    else {
        memcpy(H->table[position].value, key, strlen(key) + 1);
        H->table[position].state = Used;
    }
}

void Delete(ElemType key, pHashTable H) {
    Index position = Find(key, H);
    if(H->table[position].state == Deleted) {
        printf("重复删除元素:%s", key);
    }
    else {
        /* memset(H->table[position].value, '\0', 10); */
        H->table[position].state = Deleted;
    }
}
