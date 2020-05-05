/*************************************************************************
    > File Name: rehashing.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月05日 星期二 11时47分56秒
 ************************************************************************/

#include <stdio.h>
#include "open_adressing.h"

static int ElemNum = 0;

pHashTable Rehash(pHashTable H) {
    pHashTable newTable = InitializeTable(H->TableSize * 2);
    for(int i = 0; i < H->TableSize; i++) {
        if(H->table[i].state == Used) {
            Insert(H->table[i].value, newTable);
        }
    }
    Destory(H);
    return newTable;
}

void Rehash_Insert(ElemType key, pHashTable H) {
    if(3*ElemNum > H->TableSize) {
        H = Rehash(H);
    }
    Insert(key, H);
    ElemNum++;
}

void Rehash_Delete(ElemType key, pHashTable H) {
    Delete(key, H);
    ElemNum--;
}
