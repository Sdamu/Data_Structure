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


template <typename T>
class AVL_Tree{
private:
    AVL_Tree_Node<T> *root;     // AVL 树的根节点

public:
    AVL_Tree();
    ~AVL_Tree();

    // 获取树的高度
    int height();
    // 获取树的高度
    int max(int a, int b);

    // 前序遍历 AVL 树
    void preOrder();
    // 中序遍历 AVL 树
    void inOrder();
    // 后序遍历 AVL 树
    void postOrder();

    // (递归实现) 查找 AVL 树中键值为 key 的节点
    AVL_Tree_Node<T> *search(T key);
    // (非递归实现) 查找 AVL 树中键值为 key 的节点
    AVL_Tree_Node<T> *iterativeSearch(T key);

    // 查找最小节点：返回最小节点的键值
    T minimum();
    // 查找最大节点：返回最大节点的键值
    T maximum();

    // 将节点(key 为节点键值)插入到 AVL 树中
    void insert(T key);

    // 删除节点(key 为)
    void remove(T key);

    // 销毁 AVL 树
    void destory();

    // 打印 AVL 树
    void print();

private:
    // 获取树的高度
    int height(AVL_Tree_Node<T> *tree);

    // 前序遍历 AVL 树
    void preOrder(AVL_Tree_Node<T> *tree) const;
    // 中序遍历 AVL 树
    void inOrder(AVL_Tree_Node<T> *tree) const;
    // 后序遍历 AVL 树
    void postOrder(AVL_Tree_Node<T> *tree) const;

    // (递归实现)查找 AVL 树 x 中键值为 key 的节点
    AVL_Tree_Node<T>* search(AVL_Tree_Node<T>* x,T key) const;
    // (非递归实现)查找 AVL 树 x 中键值为 key 的节点
    AVL_Tree_Node<T>* iterativeSearch(AVL_Tree_Node<T>* x, T key) const;

    // 查找最小节点：返回 tree 为根节点的 AVL 树的最小节点
    AVL_Tree_Node<T>* minimum(AVL_Tree_Node<T>* tree);
    // 查找最大节点：返回 tree 为根节点的 AVL 树的最大节点
    AVL_Tree_Node<T>* maximum(AVL_Tree_Node<T>* tree);

    // LL: 左单旋转
    AVL_Tree_Node<T>* leftLeftRotation(AVL_Tree_Node<T>* k2);

    // RR: 右单旋转
    AVL_Tree_Node<T>* rightRightRotation(AVL_Tree_Node<T> *k1);

    // LR: 左双旋转
    AVL_Tree_Node<T>* leftRightRotation(AVL_Tree_Node<T>* k3);

    // RL: 右双旋转
    AVL_Tree_Node<T>* rightLeftRotation(AVL_Tree_Node<T>* k1);

    // 将节点 z 插入到 AVL 树中
    AVL_Tree_Node<T>* insert(AVL_Tree_Node<T>* &tree, T key);
    // 删除 AVL 树 tree 中的节点 z，并返回删除的节点
    AVL_Tree_Node<T>* remove(AVL_Tree_Node<T>* &tree, T key, AVL_Tree_Node<T> *z);

    // 销毁 AVL 树
    void destory(AVL_Tree_Node<T>* &tree);

    // 打印 AVL 树
    void print(AVL_Tree_Node<T>* tree, T key, int direction);

};

/*
 * 构造函数
 */
template <typename T>
AVL_Tree<T>::AVL_Tree() :root(nullptr){

}

/*
 * 析构函数
 */
template <typename T>
AVL_Tree<T>::~AVL_Tree() {
    destory(root);
}

/*
 * 获取 AVL 树的高度
 */
template <typename T>
int AVL_Tree<T>::height(AVL_Tree_Node<T> *tree) {
    if (tree != nullptr)
        return tree->height;

    return 0;
}

template <typename T>
int AVL_Tree<T>::height() {
    return height(root);
}






























































































































#endif //AVL_TREE_AVL_TREE_H
