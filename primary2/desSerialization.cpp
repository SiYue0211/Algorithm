/*
 * Created by dawn on 18-5-31.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<string> split(string &s, const string& c)
{
    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (pos2 != string::npos)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
    {
        v.push_back(s.substr(pos1));
    }
    return v;

}


TreeNode * createTree(vector<string> &v)
{
    string num = v[0];
    v.erase(v.begin());

    if(num == "#")
        return NULL;
    TreeNode *node = new TreeNode;
    int val = stoi(num);
    node->val = val;
    node->left = createTree(v);
    node->right = createTree(v);
    return node;
}

void preorder(TreeNode * head)
{
    if(head != NULL)
    {
        cout<< head->val<< " ";
        preorder(head->left);
        preorder(head->right);
    }

}



int main()
{
    string s = "1_2_4_#_#_5_#_#_3_6_#_#_7_#_#_";
    vector<string> v;
    v = split(s, "_");
    for (int i = 0; i < v.size(); ++i) {
        cout<< v[i]<< " ";
    }
    cout<< endl;
    TreeNode *head = createTree(v);
    preorder(head);
    cout<< endl;



}