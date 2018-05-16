/*
 * Created by Dawn on 2018/5/15.
 * 实现一个特殊的栈， 在实现栈的基本功能的基础上，在实现返回栈最小元素的操作。
 * pop, push, getMin 操作的时间复杂度O(1)
*/

#include <iostream>
#include <stack>
using namespace std;

class Stack{
private:
    stack<int> s;
    stack<int> help;
public:
    void push(int);
    void pop();
    int top();
    int getMin();
};

void Stack::push(int data) {
    s.push(data);
    if(help.empty())
        help.push(data);
    else
    {
        int temp = help.top();
        if(data < temp)
            help.push(data);
        else
            help.push(temp);
    }
}

int Stack::top() {
    return s.top();
}

void Stack::pop() {
    help.pop();
    s.pop();
}

int Stack::getMin() {
    return help.top();
}

int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(3);
    cout<< s.getMin()<< endl;
    s.pop();
    cout<< s.getMin()<< endl;
    s.pop();
    cout<< s.getMin()<< endl;
    s.pop();
    cout<< s.getMin()<< endl;



}
