/*
 * Created by dawn on 18-5-17.
 * 题目描述: 仅用队列实现栈
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack{
private:
    queue<int> q;
    queue<int> help;
    int size;
public:
    void push(int);
    void pop();
    int top();
};

void Stack::push(int x) {
    q.push(x);
}

void Stack::pop() {
    size = q.size();
    for(int i=0; i< size-1; i++)
    {
        int temp = q.front();
        help.push(temp);
        q.pop();
    }
    q.pop();
    queue<int> t = q;
    q = help;
    help = t;
}

int Stack::top() {
    return q.back();
}

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.pop();
    cout<< s.top()<< endl;
    s.pop();
    cout<< s.top()<< endl;
}