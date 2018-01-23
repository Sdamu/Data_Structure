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
    AVL_Tree_Node<T>* remove(AVL_Tree_Node<T>* &tree, AVL_Tree_Node<T> *z);

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
 * 只需要进行一次旋转即可调整为平衡状态
 *
 * 返回值：旋转后的根节点
 *
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::leftLeftRotation(AVL_Tree_Node<T> *k2) {
    AVL_Tree_Node<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;

    return k1;

}

/*
 * RR: 右单旋转
 *
 * 只需要进行一次旋转即可调整为平衡状态
 *
 * 返回值：旋转后的根节点
 *
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::rightRightRotation(AVL_Tree_Node<T> *k1) {
    AVL_Tree_Node<T> * k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;

    return k2;
}

/*
 * LR: 左双旋转
 *
 * 需要进行两次旋转方可调整为平衡状态
 * 首先要经过一次 RR 旋转，在经过一次 LL 旋转
 *
 * 返回值：旋转后的根节点
 *
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::leftRightRotation(AVL_Tree_Node<T> *k3) {
    k3->left = rightRightRotation(k3->left);

    return leftLeftRotation(k3);
}

/*
 * RL：右双旋转
 *
 * 需要进行两次旋转方可调整为平衡状态
 * 首先要经过一次 LL 旋转，再经过一次 RR 旋转
 *
 * 返回值：旋转后的根节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::rightLeftRotation(AVL_Tree_Node<T> *k1) {
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

/*
 * 将节点插入到已经平衡的 AVL 树中，并返回根节点
 *
 * 参数说明：
 *      tree：AVL 树的根节点
 *      key：插入的节点的键值
 *
 * 返回值：
 *      根节点
 */

template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::insert(AVL_Tree_Node<T>* &tree, T key) {
    if(tree == nullptr)
    {
        // 新建节点
        tree = new AVL_Tree_Node<T>(key, nullptr, nullptr);
//      if(tree == nullptr)
//      {
//          std::cout<<"ERROR: create avltree node failed!" <<std::endl;
//          return nullptr;
//      }
    }

    else if(key < tree->key)    // 小于键值，则应该插入到 tree 的左子树中
    {
        tree->left = insert(tree->left, key);       // 利用递归进行插入操作
        // 插入节点后，如果 AVL 树失去平衡，则进行相应的调节
        if(height(tree ->left) - height(tree->right) == 2)
        {
            if(key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }

    else if (key > tree->key)   // 大于键值，则应该插入到 tree 的右子树中
    {
        tree->right = insert(tree->right, key);
        // 插入节点后，如果 AVL 树失去平衡，则惊醒相应的调节
        if(height(tree->right) - height(tree->left))
        {
            if(key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }

    else    // key == tree->key
    {
        std::cout<<"添加失败，不允许添加相同的节点\n";
    }

    tree->height = max(height(tree->left), height(tree->right));

    return tree;

}

template <typename T>
void AVL_Tree<T>::insert(T key) {
    insert(root, key);
}

/*
 * 删除结点 z，并返回根节点
 *
 * 参数说明：
 *      tree：AVL 树的根节点
 *      z：要删除的节点
 *
 * 返回值：
 *      根节点
 */
template <typename T>
AVL_Tree_Node<T>* AVL_Tree<T>::remove(AVL_Tree_Node<T> *&tree, AVL_Tree_Node<T> *z) {
    // 根为空 或者 没有要删除的节点，直接返回 nullptr
    if(tree == nullptr || z == nullptr)
        return nullptr;

    // 待删除的节点在 tree 的左子树中
    if(z->key < tree->key)
    {
        tree->left = remove(tree->left, z);     // 使用递归进行删除
        // 删除节点后 如果 AVL 树失去平衡，则进行相应的调整
        if(height(tree->right) - height(tree->left) == 2)
        {
            AVL_Tree_Node<T> *r = tree->right;
            if(height(r->left) > height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }

    // 待删除的节点在 tree 的右子树中
    if(z->key > tree->key)
    {
        tree->right = remove(tree->right, z);   // 使用地柜进行删除
        // 删除节点后 如果 AVL 树失去平衡，则进行相应的调整
        if(height(tree->left) - height(tree->right) == 2)
        {
            AVL_Tree_Node<T>* l = tree->left;
            if(height(l->left) > height(l->right))
                tree = leftRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }

    else    // tree 是对应要删除的节点
    {
        // tree 的左右孩子都非空
        if ((tree->left != nullptr) && (tree->right != nullptr))
        {
            if(height(tree->left) > height(tree->right))
            {
                /*
                 * 如果tree 的左子树比右子树高
                 * 则有：
                 *      ① 找出 tree 的左子树中的最大节点
                 *      ② 将该最大节点的值赋值给 tree
                 *      ③ 删除该最大节点
                 *
                 * 这种方法类似于用 tree 的左子树中的最大节点做 tree 节点的替身
                 * 采用这种方式的好处是：删除 tree 左子树的最大节点后，AVL 树仍然是平衡的
                 */
                AVL_Tree_Node<T> *max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);   // 继续进行递归删除操作
            }
            else
            {
                /*
                 * 如果 tree 的左子树不比右子树高（也就是相等或者 右子树比左子树高）
                 * 则有：
                 *      ① 找出 tree 右子树中的最小节点
                 *      ② 将该最小节点的值 赋值 给 tree
                 *      ③ 删除该最小节点
                 *
                 * 这种方法类似于用 tree 的右子树中的最小节点做 tree 节点的替身
                 * 采用这种方式的好处是：删除 tree 的右子树中最小节点后，AVL 树仍然是平衡的
                 */
                AVL_Tree_Node<T>* min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);     // 继续进行递归删除操作
            }
        }

        else
        {
            AVL_Tree_Node<T> *tmp = tree;
            tree = (tree->left != nullptr)? tree->left:tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <typename T>
void AVL_Tree<T>::remove(T key) {
    AVL_Tree_Node<T> *z;

    if((z = search(root, key)) != nullptr)
        root = remove(root, z);
}


#endif //AVL_TREE_AVL_TREE_H
