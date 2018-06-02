/*
 * Created by dawn on 18-5-31.
 * 二叉树先序序列化
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

string ser(TreeNode *node)
{
    if(node == NULL)
    {
        return "#_";
    }
    string s;
    s += (char)(node->val + int('0'));
    s += "_";
    cout<< s<< endl;
    s += ser(node->left);
    s += ser(node->right);
    return  s;
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

    string s;
    s = ser(a_1);
    cout<< s<< endl;
}