//
// Created by Damu on 2018/1/22.
//

#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H

#include <iomanip>
#include <iostream>

// AVL 树的结点类
template <typename T>
class AVL_Tree_Node{
public:
    T key;
    int height;     // 该节点所在的高度
    AVL_Tree_Node *left;    // 左孩子
    AVL_Tree_Node *right;   // 右孩子

    AVL_Tree_Node(T value, AVL_Tree_Node *l,AVL_Tree_Node *r):
            key(value),height(0),left(l),right(r)
    {}

};

































































































































#endif //AVL_TREE_AVL_TREE_H
