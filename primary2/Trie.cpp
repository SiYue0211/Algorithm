/*
 * Created by dawn on 18-6-15.
 * 前缀树
*/
#define MAX_CHILD 26

#include <iostream>
#include <string>
using namespace std;

struct Node{
    int path; // 路过这条路径+1
    int end; // 以这个结点为尾+1
    Node * next[MAX_CHILD];
    Node(){
        path = 0;
        end = 0;

    }
};

void insert(Node *root, string str){
    int len = str.size();
    if(len == 0)
        return;
    for(int i=0; i<len; i++){
        if(root->next[str[i]-'a'] == NULL)
            root->next[str[i]-'a'] = new Node();
        root = root->next[str[i]-'a'];
        root->path++;
        if(i == len-1)
            root->end++;
    }
}

void del(Node *root, string str){
    int len = str.size();
    if(len == 0)
        return;
    for(int i=0; i<len; i++){
        if(root->next[str[i]-'a'] == NULL)
            return;
        root = root->next[str[i]='a'];
        if(root->path != 0 )
            root->path--;
        else{
            delete root;
            root = NULL;
        }

    }
}

int search(Node *root, string str){
    int len = str.size();
    if(len == 0)
        return 0;
    for (int i = 0; i < len ; ++i) {
        if(root->next[str[i]-'a'] == NULL)
            return 0;
        root = root->next[str[i]-'a'];
    }
    return root->end;
}


int main()
{
    Node * node = new Node();
    insert(node, "abc");
    insert(node, "ab");
    int result = search(node, "ab");
    cout<< result<< endl;
}


