/*************************************************************************
    > File Name: open_adressing.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月04日 星期一 13时03分59秒
 ************************************************************************/

#ifndef _OPEN_ADRESSING_H_C
#define _OPEN_ADRESSING_H_C
typedef int Index;
typedef const char *ElemType;

struct HashTable;
typedef struct HashTable* pHashTable;

pHashTable InitializeTable(int TableSize);
void Destory(pHashTable H);
Index Find(ElemType key, pHashTable H);
void Insert(ElemType key, pHashTable H);
void Delete(ElemType key, pHashTable H);
extern int Hash(ElemType key, int TableSize);

enum NodeState{Used, Empty, Deleted};

struct HashNode {
    char value[10];
    enum NodeState state;
};

typedef struct HashNode *pHashNode;

struct HashTable {
    int TableSize;
    pHashNode table;
};


#endif /* OPEN_ADRESSING_H_C */
