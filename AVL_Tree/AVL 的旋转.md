## AVL 的旋转

1. LL 旋转

   LL 失去平衡的情况，可以通过一次旋转让 AVL 树 恢复平衡。如下图所示：

   ![img](https://images0.cnblogs.com/i/497634/201403/281626153129361.jpg)

   上图中左边的图是旋转之前的树，可以看出它是不平衡的，右边是旋转后的树，从中可以发现，旋转之后的树又变成了 AVL 树，而且该旋转只需要一次即可完成。

   &emsp;&emsp;对于LL 旋转，可以这样理解：

   > LL 旋转是围绕 “失去平衡的 AVL 根节点” 进行的，也就是节点 k2；而且由于是 LL 情况，也就是 左左情况，就可以想象着用手抓住 k2 的左孩子，也就是 k1，用力摇动。从而将 k1 变为根节点，k2 变成 k1 的右子树，“k1 的右子树 成为 k2 的左子树”

   LL 的旋转代码：

   ```c++
   /*
   * LL: 左左旋转
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

       k2->height = max(height(k2->left), height(k2->left)) + 1;
       k1->height = max(height(k1->left), height(k1->right)) + 1;
       
       return k1;
       
   }
   ```

2.  RR 旋转

   理解了 LL 旋转之后，RR 旋转的理解就比较容易了。 RR 旋转是 LL 旋转的对称情况。RR 恢复平衡的旋转方法如下所示：

   ![img](https://images0.cnblogs.com/i/497634/201403/281626410316969.jpg)

   上图中左边是旋转之前的树，右边是进行 RR 旋转之后的树。可以看出，RR 旋转也只需要进行一次旋转即可完成。

   RR  旋转的代码如下所示：

   ```c++
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
       AVL_Tree_Node<T>* k2;

       k2 = k1->right;
       k1->right = k2->left;
       k2->left = k1;

       k1->height = max(height(k1->left), height(k1->right)) + 1;
       k2->height = max(height(k2->left), height(k2->right)) + 1;

       return k2;
   }
   ```

   ​

3. LR 旋转

   LR 失去平衡的情况，需要进行两次旋转才能让 AVL 树恢复平衡。如下图所示：

   ![img](https://images0.cnblogs.com/i/497634/201403/281627088127150.jpg)

   如上图，第一次旋转是围绕 k1 进行的 RR 旋转，第二次是围绕 k3 的 LL 旋转

   LR 旋转的具体代码如下所示：

   ```cpp
   template <typename T>
   AVL_Tree_Node<T>* AVL_Tree<T>::leftRightRotation(AVL_Tree_Node<T> *k3) {
       k3->left = rightRightRotation(k3->left);

       return leftLeftRotation(k3);
   }
   ```

4. RL 旋转

   RL 旋转是上述的 LR 旋转的对称情况。RL 旋转恢复平衡的旋转方法如下所示：

   ![img](https://images0.cnblogs.com/i/497634/201403/281628118447060.jpg)

   如上图所示：第一次旋转是围绕 k3 进行的 LL 旋转，第二次旋转是围绕 k1 进行的 RR 旋转

   具体代码如下所示：

   ```cpp
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
   ```

   ​