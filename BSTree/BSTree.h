//
// Created by Damu on 2018/1/12.
//

/*
 * C++ 语言实现：二叉查找树
 */


#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
class BSTNode{
public:
    T key;      // 关键字（值）
    BSTNode *left;      // 左孩子
    BSTNode *right;     // 右孩子
    BSTNode *parent;    // 父节点

    BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
            key(value),parent(p), left(l),right(r){}
};

template <class T>
class BSTree{
private:
    BSTNode<T> *mRoot;      // 根节点

public:
    BSTree();       // 构造函数
    ~BSTree();      // 析构函数

    // 前序遍历二叉树
    void preOrder();
    // 中序遍历二叉树
    void inOrder();
    // 后序遍历二叉树
    void postOrder();

    // (递归实现) 查找二叉树中键值为 key 的节点
    BSTNode<T>* search(T key);
    // (非递归实现) 查找二叉树中键值为 key 的节点
    BSTNode<T>* iterativeSearch(T key);

    // 查找最小节点，返回最小节点的键值
    T minimum();
    // 查找最大节点，返回最大节点的键值
    T maximum();

    // 查找节点 (x) 的后继节点。也就是查找二叉树中数据值大于该节点的最小节点
    BSTNode<T>* successor(BSTNode<T> *x);
    // 查找节点 (x) 的前驱节点。也就是查找二叉树中数据值小于该节点的最大节点
    BSTNode<T>* predecessor(BSTNode<T> *x);

    // 将节点插入到二叉树中
    void insert(T key);

    // 删除节点
    void remove(T key);

    // 销毁二叉树
    void destory();

    // 打印二叉树
    void print();

private:

    // 前序遍历二叉树
    void preOrder(BSTNode<T>* tree) const;
    // 中序遍历二叉树
    void inOrder(BSTNode<T>* tree) const;
    // 后序遍历二叉树
    void postOrder(BSTNode<T> *tree) const;

    // 递归实现查找二叉树中值为 key 的节点
    BSTNode<T>* search(BSTNode<T>* x, T key) const;
    // 非递归实现查找二叉树中值为 key 的节点
    BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key)const;

    // 查找最小节点：返回 tree 为根结点的二叉树的最小结点。
    BSTNode<T>* minimum(BSTNode<T>* tree);
    // 查找最大节点：返回 tree 为根节点的二叉树的最大节点
    BSTNode<T>* maximum(BSTNode<T>* tree);

    // 将节点 z 插入到二叉树中
    void insert(BSTNode<T>* &tree, BSTNode<T> *z);

    // 删除二叉树中的节点 z，并返回被删除的节点
    BSTNode<T>* remove(BSTNode<T> * &tree, BSTNode<T> *z);

    // 销毁二叉树
    void destory(BSTNode<T>* &tree);

    // 打印二叉树
    void print(BSTNode<T>* tree, T key, int direction);


};

// 构造函数
template <class T>
BSTree<T>::BSTree():mRoot(nullptr)
{

}

// 析构函数
template <class T>
BSTree<T>::~BSTree()
{
    destory();
}

// 前序遍历二叉树

template <class T>
void BSTree<T>::preOrder(BSTNode<T> *tree) const
{
    if(tree != nullptr) {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::preOrder()
{
    preOrder(mRoot);
}


// 中序遍历二叉树
template <class T>
void BSTree<T>::inOrder(BSTNode<T> *tree) const {
    if(tree != nullptr) {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <class T>
void BSTree<T>::inOrder() {
    inOrder(mRoot);
}

// 后序遍历二叉树
template <class T>
void BSTree<T>::postOrder(BSTNode<T> *tree) const {
    if(tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->key<<" ";
    }
}

template <class T>
void BSTree<T>::postOrder() {
    postOrder(mRoot);
}

// 递归实现 查找二叉树x 中 键值为 key 的节点
template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T> *x, T key) const {
    if(x == nullptr || x->key==key)
        return x;
    if(x->key > key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
BSTNode<T>* BSTree<T>::search(T key) {
    search(mRoot, key);
}


// 非递归实现 查找二叉树 x 中 键值为 key 的节点
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T> *x, T key) const {
    while((x != nullptr) && x->key != key)
    {
        if(x->key > key)
            x = x->left;
        else
            x = x->right;
    }
}

template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key) {
    iterativeSearch(mRoot, key);
}

// 查找最小节点 也就是查找最左下角的节点
template <class T>
BSTNode<T> *BSTree<T>::minimum(BSTNode<T>* tree)
{
    if(tree == nullptr)
        return nullptr;
    while(tree->left != nullptr)
        tree = tree->left;
    return tree;
}

template <class T>
T BSTree<T>::minimum() {
    BSTNode<T> * p = minimum(mRoot);
    if(p != nullptr)
        return p->key;

    return (T)nullptr;
}

// 查找最大节点 也就是查找最右下角的节点
template <class T>
BSTNode<T> *BSTree<T>::maximum(BSTNode<T> *tree) {
    if(tree == nullptr)
        return nullptr;
    while (tree != nullptr)
        tree = tree->right;
    return tree;
}

template <class T>
BSTNode<T> *BSTree<T>::maximum() {
    BSTNode<T> *p = maximum(mRoot);
    if(p != nullptr)
        return p->key;
    return(T) nullptr;
}

// 找到节点 x 的后继节点，也就是查找 二叉树中数据值大于该节点的最小节点
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x) {
    // 如果 x 存在右孩子，则 x 的后继节点为 以右孩子为根的子树的最小节点
    if(x->right != nullptr)
        return minimum(x->right);

    // 如果x 不存在右孩子，则 x 有以下两种可能：
    // 01 x 是一个左孩子，则 x 的后继节点为其父节点，
    // 02 x 是一个右孩子，则查找 x 的最低的 父节点，并且该父节点要具有左孩子，则该父节点即为所求

    BSTNode<T> *y = x->parent;
    while((y!= nullptr) && (x == y->right))
    {
        x =y;
        y =y->parent;
    }

    return y;
}

// 找到节点 x 的前驱节点，也就是查找 二叉树中数据值小于该节点的最大节点
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x) {
    // 如果 x 存在左孩子，则 x 的前驱节点为 以左孩子为根的子树的最大节点
    if(x->left != nullptr)
        return maximum(x->left);

    // 如果 x 不存在右孩子，则 x 有一下两种可能
    // 01 x 是一个右孩子，则 x 的前驱节点就是其父节点
    // 02 x 是一个左孩子，则查找x 的最低的父节点，并且该父节点要具有右孩子，则该父节点即为所求

    BSTNode<T>* y = x->parent;
    while ((y != nullptr) && (x == y->left))
    {
        x = y;
        y =y->parent;
    }

    return y;
}


/*
 * 将节点插入到二叉树中，其中 key 为节点键值
 * 参数说明：
 *      tree：二叉树的根节点
 *      z: 插入的节点
 */
template <class T>
void BSTree<T>::insert(BSTNode<T> *&tree, BSTNode<T> *z) {
    BSTNode<T> *y = nullptr;
    BSTNode<T> *x = tree;

    // 查找 z 需要插入的位置
    while (x != nullptr)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == nullptr)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

/*
 * 将节点插入到二叉树中 其中key 为节点键值
 *
 * 参数说明：
 *      tree: 二叉树的分界点
 *      key:  插入节点的键值
 */
template <class T>
void BSTree<T>::insert(T key) {
    BSTNode<T> *z= nullptr;

    // 如果新建节点失败，直接返回
    if((z = new BSTNode<T>(key, nullptr, nullptr, nullptr)) == nullptr)
        return ;

    insert(mRoot, z);

}

/*
 * 删除节点(z), 并返回被删除的节点
 *
 * 参数说明：
 *      tree: 二叉树的根节点
 *      z   : 删除的节点
 */

template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T> *&tree, BSTNode<T> *z) {
    BSTNode<T> *x = nullptr;
    BSTNode<T> *y = nullptr;

    if((z->left == nullptr) || z->right == nullptr)
        y =z;
    else
        y = successor(z);

    if(y->left != nullptr)
        x = y->left;
    else
        x= y->right;

    if (x != nullptr)
        x->parent = y->parent;

    if (y->parent == nullptr)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z)
        z->key = y->key;

    return y;

}

/*
 * 删除节点 z，并返回被删除的节点
 *
 * 参数说明：
 *      tree: 二叉树的根节点
 *      z   : 删除的节点
 */
template <class T>
void BSTree<T>::remove(T key) {
    BSTNode<T> *z, *node;
    if((z = search(mRoot, key)) != nullptr)
        if((node = remove(mRoot, z))!= nullptr)
            delete node;
}























#endif //BSTREE_BSTREE_H
