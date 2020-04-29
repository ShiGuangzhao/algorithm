/*************************************************************************
    > File Name: avl.c
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2019年12月16日 星期一 11时28分03秒
 ************************************************************************/

#include <stdio.h>
#include "avl.h"

AVLNode newNode(int number) {
    AVLNode temp = AVLNode(malloc(sizeof(treeNode)));
    temp->data = number;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return temp;
}

AVLTree init(int data[], int count) {
    AVLNode root = newNode(data[0]);
    for(int i = 1; i < count; i++) {
        insert(root, data[i]);
    }
    return root;
}

AVLTree find(AVLTree tree, int number) {
    if(tree == NULL || tree->data == number) {
        return tree;
    }
    else if(tree->data > number) {
        return find(tree->left, number);
    }
    else {
        return find(tree->right, number);
    }
}

AVLTree insert (AVLTree tree, int number) {
    if(tree->data < number) {
        if(tree->right == NULL) {
            tree->right = newNode(number);
        }
        else {
            tree->right = insert(tree->right, number);
        }
    }
    else if(tree->data > number) {
        if(tree->left == NULL) {
            tree->left = newNode(number);
        }
        else {
            tree->left = insert(tree->left, number);
        }
    }
    else {
        printf("重复插入元素%d,插入操作被忽略\n", number);
    }
    return tree;
}

