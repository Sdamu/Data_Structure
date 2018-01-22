//
// Created by Damu on 2018/1/22.
//

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
    // ������Ӹ��������
};

template <class Type> class BST;    // ǰ������

template <class Type>
class BstNode   // ���ڵ�
{
    // ������Ԫ��
    friend class BST<Type>; // ˵�� BST�� ��BstNode ����Ԫ��
public:
    Element<Type> data;   // �ڵ��ڵ�����
    BstNode<Type> *LeftChild;    // ����
    BstNode<Type> *RightChild;   // �Һ���
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
    void Remove1(BstNode<Type> * &node);     // ɾ����㣬���ø���ɾ��
    void Merging_Remove(const Element<Type> &x);
    void Remove2(const Element<Type> &x);       // ���õݹ��˼������ڲ��ڵ��ɾ��
       // ɾ����㣬���õݹ����ɾ��

    // ����ɾ������
    // ǰ�����  preOrder
    void preOrder();
    // �������  inOrder
    void inOrder();
    // ��������  postOrder
    void postOrder();
    // �������  levelOrder
    void levelOrder();
    // �������ֵ
    Type maximum();
    // ������Сֵ
    Type minimum();
    BstNode<Type>* Search(const Element<Type> &x);
    BstNode<Type> *Search(BstNode<Type>*, const Element<Type> &);   // �ݹ����
    BstNode<Type>* IterSearch(const Element<Type>& );   // ��������
    void display()
    {
        std::cout<<"\n";
        if(root)
            root->display(1);
        else
            std::cout<<"����һ�ſ���\n";
    }
private:
    BstNode<Type> *root;    // ���ڵ�
    void preOrder(BstNode<Type>*t); // ǰ�����
    void inOrder(BstNode<Type> *t); // �������
    void postOrder(BstNode<Type> *t);   // �������
    void levelOrder(BstNode<Type> *t);  // �������
    BstNode<Type>* maximum(BstNode<Type> *tree);    // �������ֵ
    BstNode<Type>* minimum(BstNode<Type> *tree);    // ������Сֵ
    void Remove2(const Element<Type> &x, BstNode<Type> * &t);
};


template <class Type>
void BstNode<Type>::display(int i) {
    // ��ʾ��ǰ�ڵ����� �Լ� ����������������ȫ������
    std::cout<<"Position: "<<i<<", data.key = "<<data.key<<"\n";
    if(LeftChild)
        LeftChild->display(2*i);    // ���ӵ�λ��
    if(RightChild)
        RightChild->display(2*i+1); // �Һ��ӵ�λ��
}

template <class Type>
Boolean BST<Type>::Insert(const Element<Type> &x) {
    BstNode<Type> *p = root;    // ָ����ڵ��ָ��
    BstNode<Type> *q = nullptr; // ָ��ڵ� p �ĸ�ָ��
    // insert ֮ǰ����Ҫ���в��Ҳ���
    // Ҫ�ҵ�һ�����ʵ�λ�ý��в������
    while(p)
    {
        q = p;
        if(x.key == p->data.key) return FALSE;  // �����ظ���ʧ��
        if(x.key < p->data.key)
        {
            p = p->LeftChild;
        }
        else
        {
            p = p->RightChild;
        }
    }
    // ��ѭ�����������Ǿ��ҵ���һ������λ�� q
    p = new BstNode<Type>;
    p->LeftChild = p->RightChild = nullptr;
    p->data=x;
    if (!root)
        root = p;
    else if(x.key < q->data.key)
        q->LeftChild = p;
    else
        q->RightChild = p;
    return TRUE;    // ��ʾ����ɹ�
}

// ����
template<class Type>
BstNode<Type>* BST<Type>::Search(const Element<Type> &x) {
    return Search(root, x);     // �Ӹ��ڵ㿪ʼ��
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

// ��������
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

// ǰ�����
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

// �������
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

// �������
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

// �������
template <typename Type>
void BST<Type>::levelOrder(BstNode<Type> *t) {
    // ���������ɲ������
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

// ����ɾ���㷨
template <typename Type>
void BST<Type>::Remove1(BstNode<Type>* &node) {
    BstNode<Type> *tmp = node;
    if (node != nullptr)
    {
        if (node->RightChild == nullptr)  // û��������
            node = node->LeftChild;     // ָ������Ů
        else if (node -> LeftChild == nullptr)  // û������Ů
            node = node->RightChild;    // ָ������Ů
        else
        {
            tmp = node->LeftChild;  // �ҵ������������ҽ��
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

// �������ֵ
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

// ������Сֵ
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


/*
 * ��һ������ɾ��һ����ڲ�����
 * ���� x ��Ҫ��ɾ������
 * ���� t �Ǹ������ĸ�
 * �ø��������µĸ�
 */
template <typename Type>
void BST<Type>::Remove2(const Element<Type> &x, BstNode<Type> *&t) {
    if(t == nullptr)
        return;         // û���ҵ�Ҫɾ�����ʲôҲ������
    if(x.key < t->data.key)
        Remove2(x,t->LeftChild);
    else if(x.key > t->data.key)
        Remove2(x, t->RightChild);
    else if (t->LeftChild != nullptr && t->RightChild != nullptr)   // ��������Ů
    {
        t->data.key = minimum(t->RightChild)->data.key;
        Remove2(t->data, t->RightChild);
    }
    else
    {
        BstNode<Type> * oldNode = t;
        t = (t->LeftChild != nullptr) ? t->LeftChild : t->RightChild;
        delete oldNode;
    }
}

template <typename Type>
void BST<Type>::Remove2(const Element<Type> &x) {
    BstNode<Type> *t = root;
    if(t != nullptr)
        Remove2(x, t);
    else
        return ;
}


#endif //BSTREE_BSTREE_H
