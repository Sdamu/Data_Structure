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
    // 比较两个数值的大小
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

/*
 * 比较两个值的大小
 */
template <typename T>
int AVL_Tree<T>::max(int a, int b) {
    return a>b ? a:b;
}

/*
 * 前序遍历 AVL 树
 */
template <typename T>
void AVL_Tree<T>::preOrder(AVL_Tree_Node<T> *tree) const {
    if (tree != nullptr)
    {
        std::cout<<tree->key<<"\t";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <typename T>
void AVL_Tree<T>::preOrder() {
    preOrder(root);
}

/*
 * 中序遍历 AVL 树
 */
template <typename T>
void AVL_Tree<T>::inOrder(AVL_Tree_Node<T> *tree) const {
    if(tree != nullptr)
    {
        inOrder(tree->left);
        std::cout<<tree->key<<"\t";
        inOrder(tree->right);
    }
}

template <typename T>
void AVL_Tree<T>::inOrder() {
    inOrder(root);
}

/*
 * 后序遍历 AVL 树
 */
template <typename T>
void AVL_Tree<T>::postOrder(AVL_Tree_Node<T> *tree) const {
    if(tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->left);
        std::cout<<tree->key<<"\t";
    }
}

template <typename T>
void AVL_Tree<T>::postOrder() {
    postOrder(root);
}

/*
 * 递归实现 查找 AVL 树中键值为 key 的节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::search(AVL_Tree_Node<T> *x, T key) const {
    if(x == nullptr || x->key == key)
        return x;
    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::search(T key) {
    return search(root, key);
}

/*
 * 非递归实现 查找 AVL 树中键值为 key 的节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::iterativeSearch(AVL_Tree_Node<T> *x, T key) const {
    while((x != nullptr) && (x->key != key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::iterativeSearch(T key) {
    return iterativeSearch(root, key);
}

/*
 * 查找最小节点：返回 tree 为根节点的 AVL 树的最小节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::minimum(AVL_Tree_Node<T> *tree) {
    if(tree == nullptr)
        return nullptr;

    while(tree->left != nullptr)
        tree = tree->left;

    return tree;
}

template <typename T>
T AVL_Tree<T>::minimum() {
    AVL_Tree_Node<T> *p = minimum(root);
    if(p != nullptr)
        return p->key;
    return T(nullptr);
}

/*
 * 查找最大节点：返回 tree 为根节点的 AVL 树的最大节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::maximum(AVL_Tree_Node<T> *tree) {
    if (tree == nullptr)
        return nullptr;
    while(tree->right != nullptr)
        tree = tree->right;

    return tree;
}
template <typename T>
T AVL_Tree<T>::maximum() {
    AVL_Tree_Node<T> *p = minimum(root);
    if(p != nullptr)
        return p->key;
    return T(nullptr);
}


/*
 * LL: 左单旋转
 *
 * 返回值：旋转后的根节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::leftLeftRotation(AVL_Tree_Node<T> *k2) {
    AVL_Tree_Node<T> *k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), height(k1->right)) + 1;

    return k1;
}

/*
 * RR: 右单旋转
 *
 * 返回值：旋转后的根节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::rightRightRotation(AVL_Tree_Node<T> *k1) {
    AVL_Tree_Node<T> *k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) +1;
    k2->height = max(height(k2->left), height(k2->right)) +1;

    return k2;

}






















































































































#endif //AVL_TREE_AVL_TREE_H
