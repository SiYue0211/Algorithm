/*
 * Created by dawn on 18-5-17.
 * 题目： 仅用栈结构实现队列
*/

# include <iostream>
# include <stack>
using namespace std;

class Queue{
private:
    stack<int> s1;
    stack<int> s2;
    int temp;
public:
    void push(int);
    void pop();
    int top();
};

void Queue::push(int x) {
    if (s1.empty()) {
        if (s2.empty()) {
            s1.push(x);
        }
        else
        {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
        }
            s1.push(x);
        }
    }
    else {
        if (!s2.empty())
            cout << "s1, s2同时有数据" << endl;
        else
            s1.push(x);
    }
}

void Queue::pop()
{
    if(s1.empty() && s2.empty())
        cout << "队列为空"<< endl;
    else if(!s1.empty() && !s2.empty())
        cout << "两个栈同时有数据"<< endl;
    else
    {
        if(!s2.empty())
            s2.pop();
        if(!s1.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
}

int Queue::top()
{
    if(s1.empty() && s2.empty())
        cout << "队列为空"<< endl;
    else if(!s1.empty() && !s2.empty())
        cout << "两个栈同时有数据"<< endl;
    else
    {
        if(!s2.empty())
            return s2.top();
        if(!s1.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
}

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<< q.top()<< endl;
    q.pop();
    cout<< q.top()<< endl;
    q.pop();
    cout<< q.top()<< endl;
    q.pop();
    cout<< q.top()<< endl;
}










