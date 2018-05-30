/*
 * Created by dawn on 18-5-30.
 * 题目描述：和node_next那个题一样，只是这次是找前驱
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

int pre_node(TreeNode *a)
{
    TreeNode *t;
    //如果有左子树，那么就是左子树最右结点
    if(a->left)
    {
        a = a->left;
        while (a->right)
            a = a->right;
        return a->val;
    }
    // 如果没有左子树，那么找它是哪个结点的右孩子
    else
    {
        t = a->parent;
        while(t)
        {
            if(t->right == a)
                return t->val;
            a = t;
            t = t->parent;
        }
        return 0;
    }
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
    int result = pre_node(a_7);

    cout<< result<< endl;
}

