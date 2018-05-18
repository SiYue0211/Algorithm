/*
 * Created by dawn on 18-5-18.
 * 反转单向链表
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class list{
public:
    node *h;
    void head(list &l, int n);
    void insert(list &l, int n, int num);
    void del(list &l, int n);
    void search(list &l, int n);
    void reverse(list &l);
};

void list::head(list &l, int n) {
    // 头插法，倒序
    node *p = new node;
    l.h = p;
    p ->data = n;
    p ->next =NULL;
    for (int i = 0; i < n; ++i) {
        node *q = new node;
        cin >> q->data;
        q->next = p->next;
        p->next = q;
    }
}

void list::insert(list &l, int n, int num)
{
    // 在第n个位置插入num
    node *p = l.h;
    for (int i = 0; i < n; ++i) {
        p = p->next;
    }
    node *q = new node;
    q->data = num;
    q->next = p->next;
    p->next = q;
}

void list::del(list &l, int n) {
    node *p = l.h;
    node *q =new node;
    for (int i = 0; i < n; ++i) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;
}

void list::search(list &l, int n) {
    node *p = l.h;
    for (int i = 0; i < n; ++i) {
        p = p->next;
    }
    cout<< p->data<< endl;
}

void list::reverse(list &l) {
    node *p = l.h;
    node *q;
    p = p->next;
    while(p->next)
    {
        q = p->next;
        p->next = q->next;
        q->next = p;
    }
}

int main()
{
    list l;
    l.head(l, 3);
    l.reverse(l);
}
























