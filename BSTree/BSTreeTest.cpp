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

    cout<<"\n"<<m.Insert(a)<<endl;    // a = 5; Ҳ���� root
    cout<<m.Insert(b)<<endl;
    cout<<m.Insert(c)<<endl;
    cout<<m.Insert(d)<<endl;    // d �����ظ��������ʧ��
    cout<<m.Insert(e)<<endl;
    cout<<m.Insert(f)<<endl;
    cout<<m.Insert(g)<<endl;
    cout<<m.Insert(h)<<endl;
    cout<<m.Insert(i)<<endl;
    cout<<m.Insert(j)<<endl;
    m.display();

    BstNode<int>* p = m.Search(f);
    cout<<"�ҵ����ǣ�"<<p->data.key<<endl;

    BstNode<int>* p2 = m.IterSearch(e);
    cout<<"�ҵ����ǣ�"<<p2->data.key<<endl;

    cout<<endl;
    cout<<"ǰ�������";
    m.preOrder();
    cout<<endl;
    cout<<"���������";
    m.inOrder();
    cout<<endl;
    cout<<"���������";
    m.postOrder();
    cout<<endl;
    cout<<"���������";
    m.levelOrder();
    cout<<endl;
    //m.Merging_Remove(c);
    //cout<<"ɾ�� h ����Ĳ��������";
    //m.levelOrder();
    // cout<<"Hello Test"<<endl;

    // �ҳ����ֵ
    cout<<"���ֵΪ��"<<m.maximum()<<endl;
    // �ҳ���Сֵ
    cout<<"��СֵΪ��"<<m.minimum()<<endl;


    return 0;
}