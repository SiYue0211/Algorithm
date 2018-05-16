/*
 * Created by Dawn on 2018/5/14.
 * 用定常数组实现队列和栈
*/
#include <iostream>
using namespace std;

int len = 5;

class ArrayStack{
private:
    int arr[5] = {0};
    int index = 0;
public:
    void push(int obj);
    int pop();
    int peek();

};


int ArrayStack::peek() {
    if (index == 0)
        throw "empty";
    return arr[index - 1];
}

void ArrayStack::push(int obj) {
    if (index == len)
        throw "full";
    arr[index++] = obj;
}

int ArrayStack::pop() {
    if (index == 0)
        throw "empty";
    return arr[--index];
}

class ArrayQueue{
private:
    int arr[5] = {0};
    int size = 0;
    int start = 0;
    int end = 0;
    int temp;
public:
    void push(int obj);
    int pop();
};

void ArrayQueue::push(int obj) {
    if(size < len) {
        arr[end] = obj;
        size++;
    }
    else
        cout<< "queue full"<< endl;
    end = end == len - 1 ? 0 : end + 1;
}

int ArrayQueue::pop() {
    if(size != 0)
    {
        size--;
        temp = arr[start];
    }
    else
        cout<< "queue empty"<< endl;
    start = start == len - 1 ? 0 : start + 1;
    return temp;
}



int main()
{
//    ArrayStack s;
//    s.push(10);
//    s.push(5);
//    s.push(5);
//    s.push(5);
//    s.push(5);
//    s.push(5);
//    cout << s.pop() << endl;
//    cout << s.pop() <<endl;
//    cout << s.pop() <<endl;

    ArrayQueue q;
    q.push(3);

    q.push(4);
    q.push(4);
    q.push(4);q.push(4);q.push(4);

    cout<< q.pop()<< endl;
    cout<< q.pop()<< endl;
}
