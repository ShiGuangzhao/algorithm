/*************************************************************************
    > File Name: separate_chaining.h
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年05月03日 星期日 16时48分26秒
 ************************************************************************/

#ifndef _SEPARATE_CHAINING_H_C
#define _SEPARATE_CHAINING_H_C
struct ListNode;
typedef struct ListNode *pListNode;
typedef struct ListNode *pList;
struct HashTable;
typedef struct HashTable *pHashTable;

struct ListNode {
    char value[10];
    pListNode next;
};

struct HashTable {
    int TableSize;
    pList *head;
};


/* ********
 * 初始化表格，分配表数组
 * *****/
pHashTable InitializeTable(int TableSize);
/* ********
 * 查找，查找hash(key)的链表
 * ****/
pListNode Find(const char *key, pHashTable H);
/* ******
 * 插入到hash(key)的链表
 * ***/
void Insert(const char *key, pHashTable H);
/* ******
 * 清空表
 * ***/
void Destory(pHashTable H);
/* ****
 * 删除节点
 * ***/
void Delete(const char *key, pHashTable H);
extern int Hash(const char *key, int TableSize);

#endif /* SEPARATE_CHAINING_H_C */
