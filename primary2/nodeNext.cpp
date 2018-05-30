/*
 * Created by dawn on 18-5-30.
 * 题目描述：
 *      在二叉树中找到一个节点的后继节点。现在有一种新的二叉树节点类型如下：
 *      public class Node { public int value; public Node left;
 *      public Node right; public Node parent;
 *      public Node(int data) { this.value = data; }
 *      }
 *      该结构比普通二叉树节点结构多了一个指向父节点的parent指针。 假
 *      设有一 棵Node类型的节点组成的二叉树， 树中每个节点的parent指针
 *      都正确地指向 自己的父节点， 头节点的parent指向null。 只给一个在
 *      二叉树中的某个节点 node， 请实现返回node的后继节点的函数。 在二
 *      叉树的中序遍历的序列中， node的下一个节点叫作node的后继节点。
 * 思路： 如果这个结点有右结点，那么后继一定在右子树的最左结点。
 *       如果无右结点，那么找哪个结点的左子树的最后一个结点是我们提供的结点。
 *       具体方法：往前找parent，如果parent的左结点是我们的结点，则返回parent
 *               否则，当前结点变为parent，继续往上找。。。
*/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    };

int find_left(TreeNode * a)
{
    TreeNode *t;
    while(a->left)
    {
        a = a->left;
    }
    return a->val;

}

// 找到当前结点的后继结点
int next_node(TreeNode *a)
{
    TreeNode * t;
    //如果有右子树，那么后继一定在右子树最左的结点
    if(a->right)
    {
        return find_left(a->right);
    }
    //如果没有有子树，那么看这个结点是哪个左子树的最后一个结点
    else
    {
        do
        {
            t = a->parent;
//            cout<< "t= "<< t->val<< endl;
            if (t->left == a)
                return t->val;
            else
            {
                a = t;
//                cout<< a->val<< endl;
            }

        }while (a->parent != NULL);
    }
    return 0;
}



int main()
{
    TreeNode *a_1 = new TreeNode;
    TreeNode *a_2 = new TreeNode;
    TreeNode *a_3 = new TreeNode;
    TreeNode *a_4 = new TreeNode;
    TreeNode *a_5 = new TreeNode;
    TreeNode *a_6 = new TreeNode;
    TreeNode *a_7 = new TreeNode;
    a_1->val = 1;
    a_2->val = 2;
    a_3->val = 3;
    a_4->val = 4;
    a_5->val = 5;
    a_6->val = 6;
    a_7->val = 7;
    a_1->left = a_2;
    a_1->right = a_3;
    a_2->left = a_4;
    a_2->right = a_5;
    a_3->left = a_6;
    a_3->right = a_7;
    a_1->parent = NULL;
    a_2->parent = a_1;
    a_3->parent = a_1;
    a_4->parent = a_2;
    a_5->parent = a_2;
    a_6->parent = a_3;
    a_7->parent = a_3;
    int result = next_node(a_3);

    cout<< result<< endl;
}


