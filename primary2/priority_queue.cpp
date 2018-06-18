/*
 * Created by dawn on 18-6-15.
 * 优先级队列
*/

#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int &a, int &b){
        return a > b;
    }
};

int main()
{
    priority_queue<int> q;
    priority_queue<int, vector<int>, cmp > q2;
    q2.push(1);
    q2.push(2);
    cout<< q2.size()<< endl;
    cout<< q2.top()<< endl;
    q2.pop();
    cout<< q2.top()<< endl;
}

