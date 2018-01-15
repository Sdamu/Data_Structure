#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
    BST<int> m;
    Element<int> a, b, c, d, e, f, g, h, i, j ,k ,l;
    a.key = 5;
    b.key = 3;
    c.key = 11;
    d.key = 3;
    e.key = 15;
    f.key = 2;
    g.key = 8;
    h.key = 22;
    i.key = 20;
    j.key = 9;

    cout<<"\n"<<m.Insert(a)<<endl;    // a = 5; 也就是 root
    cout<<m.Insert(b)<<endl;
    cout<<m.Insert(c)<<endl;
    cout<<m.Insert(d)<<endl;    // d 数据重复，会插入失败
    cout<<m.Insert(e)<<endl;
    cout<<m.Insert(f)<<endl;
    cout<<m.Insert(g)<<endl;
    cout<<m.Insert(h)<<endl;
    cout<<m.Insert(i)<<endl;
    cout<<m.Insert(j)<<endl;
    m.display();

    BstNode<int>* p = m.Search(f);
    cout<<"找到的是："<<p->data.key<<endl;

    BstNode<int>* p2 = m.IterSearch(e);
    cout<<"找到的是："<<p2->data.key<<endl;

    cout<<endl;
    cout<<"前序遍历：";
    m.preOrder();
    cout<<endl;
    cout<<"中序遍历：";
    m.inOrder();
    cout<<endl;
    cout<<"后序遍历：";
    m.postOrder();
    cout<<endl;
    cout<<"层序遍历：";
    m.levelOrder();
    cout<<endl;
    //m.Merging_Remove(c);
    //cout<<"删除 h 结点后的层序遍历：";
    //m.levelOrder();
    // cout<<"Hello Test"<<endl;

    // 找出最大值
    cout<<"最大值为："<<m.maximum()<<endl;
    // 找出最小值
    cout<<"最小值为："<<m.minimum()<<endl;


    return 0;
}