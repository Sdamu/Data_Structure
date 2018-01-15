//
// Created by Damu on 2018/1/15
//

/*
 * C++ 语言实现：二叉查找树
 */


#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

#include <iostream>
#include <queue>

enum Boolean {FALSE, TRUE};



template <class Type>
class Element
{
public:
    Type key;
    // 可以添加更多的数据
};

template <class Type> class BST;    // 前置声明

template <class Type>
class BstNode   // 树节点
{
    // 做成友元类
    friend class BST<Type>; // 说明 BST类 是BstNode 的友元类
public:
    Element<Type> data;   // 节点内的数据
    BstNode<Type> *LeftChild;    // 左孩子
    BstNode<Type> *RightChild;   // 右孩子
    void display(int i);
};

template <class Type>
class BST
{
public:
    BST(BstNode<Type> *init = 0)
    {
        root = init;
    }

    Boolean Insert(const Element<Type> &x);
    void Remove1(BstNode<Type> * &node);     // 删除结点，采用复制删除
    void Merging_Remove(const Element<Type> &x);
    Boolean Remove2(const Element<Type> &x);    // 删除结点，采用递归进行删除

    // 增加删除操作
    // 前序遍历  preOrder
    void preOrder();
    // 中序遍历  inOrder
    void inOrder();
    // 后续遍历  postOrder
    void postOrder();
    // 层序遍历  levelOrder
    void levelOrder();
    // 查找最大值
    Type maximum();
    // 查找最小值
    Type minimum();
    BstNode<Type>* Search(const Element<Type> &x);
    BstNode<Type> *Search(BstNode<Type>*, const Element<Type> &);   // 递归查找
    BstNode<Type>* IterSearch(const Element<Type>& );   // 迭代查找
    void display()
    {
        std::cout<<"\n";
        if(root)
            root->display(1);
        else
            std::cout<<"这是一颗空树\n";
    }
private:
    BstNode<Type> *root;    // 根节点
    void preOrder(BstNode<Type>*t); // 前序遍历
    void inOrder(BstNode<Type> *t); // 中序遍历
    void postOrder(BstNode<Type> *t);   // 后序遍历
    void levelOrder(BstNode<Type> *t);  // 层序遍历
    BstNode<Type>* maximum(BstNode<Type> *tree);    // 查找最大值
    BstNode<Type>* minimum(BstNode<Type> *tree);    // 查找最小值
};


template <class Type>
void BstNode<Type>::display(int i) {
    // 显示当前节点数据 以及 左子树和右子树的全部数据
    std::cout<<"Position: "<<i<<", data.key = "<<data.key<<"\n";
    if(LeftChild)
        LeftChild->display(2*i);    // 左孩子的位置
    if(RightChild)
        RightChild->display(2*i+1); // 右孩子的位置
}

template <class Type>
Boolean BST<Type>::Insert(const Element<Type> &x) {
    BstNode<Type> *p = root;    // 指向根节点的指针
    BstNode<Type> *q = nullptr; // 指向节点 p 的父指针
    // insert 之前首先要进行查找操作
    // 要找到一个合适的位置进行插入操作
    while(p)
    {
        q = p;
        if(x.key == p->data.key) return FALSE;  // 发生重复，失败
        if(x.key < p->data.key)
        {
            p = p->LeftChild;
        }
        else
        {
            p = p->RightChild;
        }
    }
    // 当循环结束后，我们就找到了一个插入位置 q
    p = new BstNode<Type>;
    p->LeftChild = p->RightChild = nullptr;
    p->data=x;
    if (!root)
        root = p;
    else if(x.key < q->data.key)
        q->LeftChild = p;
    else
        q->RightChild = p;
    return TRUE;    // 表示插入成功
}

// 查找
template<class Type>
BstNode<Type>* BST<Type>::Search(const Element<Type> &x) {
    return Search(root, x);     // 从根节点开始找
}

template <class Type>
BstNode<Type>* BST<Type>::Search(BstNode<Type> *b, const Element<Type> &x) {
    if(!b)
        return nullptr;
    if(x.key == b->data.key)
        return b;
    if(x.key < b->data.key)
        return Search(b->LeftChild, x);
    return Search(b->RightChild, x);
}

// 迭代查找
template <class Type>
BstNode<Type>* BST<Type>::IterSearch(const Element<Type> &x) {
    for(BstNode<Type>* t =root;t;)
    {
        if(x.key == t->data.key)
            return t;
        if (x.key < t->data.key)
            t = t->LeftChild;
        else
            t = t->RightChild;
    }
    return nullptr;
}

// 前序遍历
template <class Type>
void BST<Type>::preOrder(BstNode<Type> *t) {
    if(t != nullptr)
    {
        std::cout<<t->data.key<<"\t";
        preOrder(t->LeftChild);
        preOrder(t->RightChild);
    }
}

template <class Type>
void BST<Type>::preOrder() {
    BstNode<Type>* t = root;
    preOrder(t);
}

// 中序遍历
template <class Type>
void BST<Type>::inOrder(BstNode<Type> *t) {
    if(t != nullptr)
    {
        inOrder(t->LeftChild);
        std::cout<<t->data.key<<"\t";
        inOrder(t->RightChild);
    }
}

template <typename Type>
void BST<Type>::inOrder() {
    BstNode<Type> * t = root;
    inOrder(t);
}

// 后序遍历
template <typename Type>
void BST<Type>::postOrder(BstNode<Type> *t) {
    if(t != nullptr)
    {
        postOrder(t->LeftChild);
        postOrder(t->RightChild);
        std::cout<<t->data.key<<"\t";
    }
}

template <typename Type>
void BST<Type>::postOrder() {
    BstNode<Type>* t = root;
    postOrder(t);
}

// 层序遍历
template <typename Type>
void BST<Type>::levelOrder(BstNode<Type> *t) {
    // 引入队列完成层序遍历
    std::queue<BstNode<Type> *> q;
    if(t != nullptr)
    {
        q.push(t);
        while(!q.empty())
        {
            t = q.front();
            std::cout<<t->data.key<<"\t";
            q.pop();
            if(t->LeftChild != nullptr)
                q.push(t->LeftChild);
            if(t->RightChild != nullptr)
                q.push(t->RightChild);
        }
    }
}

template <typename Type>
void BST<Type>::levelOrder() {
    BstNode<Type> * t = root;
    levelOrder(t);
}

// 复制删除算法
template <typename Type>
void BST<Type>::Remove1(BstNode<Type>* &node) {
    BstNode<Type> *tmp = node;
    if (node != nullptr)
    {
        if (node->RightChild == nullptr)  // 没有右子树
            node = node->LeftChild;     // 指向左子女
        else if (node -> LeftChild == nullptr)  // 没有左子女
            node = node->RightChild;    // 指向右子女
        else
        {
            tmp = node->LeftChild;  // 找到左子树的最右结点
            while(tmp->RightChild != nullptr)
                tmp = tmp->RightChild;
            tmp->RightChild = node->RightChild;

            tmp = node;
            node = node->LeftChild;
        }
        delete tmp;
    }
}

template <typename Type>
void BST<Type>::Merging_Remove(const Element<Type> &x) {
    BstNode<Type> *node = root;
    BstNode<Type> *prev = nullptr;
    while(node != nullptr)
    {
        if(node->data.key == x.key)
            break;
        prev = node;
        if (node->data.key < x.key)
            node = node->RightChild;
        else
            node = node->LeftChild;
    }
    if (node != nullptr && node->data.key == x.key)
    {
        if(node == root)
            Remove1(root);
        else if(prev->LeftChild == node)
            Remove1(prev->LeftChild);
        else
            Remove1(prev->RightChild);

    }

}

// 查找最大值
template <typename Type>
BstNode<Type>*  BST<Type>::maximum(BstNode<Type> *tree) {
    if(tree == nullptr)
        return nullptr;
    while(tree->RightChild != nullptr)
        tree = tree->RightChild;
    return tree;
}

template <typename Type>
Type BST<Type>::maximum() {
    BstNode<Type> *p = maximum(root);
    if(p != nullptr)
        return p->data.key;

}

// 查找最小值
template <typename Type>
BstNode<Type>* BST<Type>::minimum(BstNode<Type> *tree) {
    if(tree == nullptr)
        return nullptr;
    while(tree->LeftChild != nullptr)
        tree = tree->LeftChild;
    return tree;
}

template <typename Type>
Type BST<Type>::minimum() {
    BstNode<Type> *p= minimum(root);
    if(p != nullptr)
        return p->data.key;
}




#endif //BSTREE_BSTREE_H
