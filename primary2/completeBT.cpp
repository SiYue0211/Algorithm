/*
 * Created by dawn on 18-6-5.
 * 题目要求：判断一棵树是否是一棵完全二叉树
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isCompleteBT(TreeNode *node)
{
    if(node == NULL)
        return true;
    if(node->left == NULL && node->right == NULL)
        return true;
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        bool isLeft = false;
        bool isRight = false;
        if(temp->left)
        {
            q.push(temp->left);
            isLeft = true;
        }

        if(temp->right)
        {
            q.push(temp->right);
            isRight = true;
        }

        if(isRight == true && isLeft == false)
            return false;
        if((isLeft == true && isRight == false) || (isLeft == false && isRight == false))
        {
            while(!q.empty())
            {
                temp = q.front();
                q.pop();
                if(!(temp->left == NULL && temp->right == NULL))
                    return false;
            }
            return true;
        }

    }
    return true;
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
//    a_2->left = a_4;
//    a_2->right = a_5;
    a_3->left = a_6;
    a_3->right = a_7;
    bool result = isCompleteBT(a_1);
    cout<< result<< endl;
}
