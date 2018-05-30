/*
 * Created by dawn on 18-5-21.
 * 打印两个有序链表的公共部分
*/

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
};

class list{
public:
    node *h;
    void head(list& l, int n);
    void print(list &l);
};

void list::head(list &l, int n) {
    //头插法
    node *p = new node;
    l.h = p;
    p->data = n;
    p->next = NULL;
    for (int i = 0; i < n; ++i) {
        node * q = new node;
        cin >> q->data;
        q->next = l.h->next;
        l.h->next = q;
    }
}

void list::print(list &l) {
    node *p = l.h;
    p = p->next;
    while (p)
    {
        cout<< p->data<< ' ';
        p = p->next;
    }
    cout<< endl;
}

void find_same(list &l1, list &l2)
{
    node *p = l1.h->next;
    node *q = l2.h->next;
    while(p && q)
    {
        if(p->data == q->data)
        {
            cout<< p->data<< " ";
            p = p->next;
            q = q->next;
        }

        else if(p->data < q->data)
            p = p->next;

        else if(q->data < p->data)
            q = q->next;
    }

}

int main()
{
    list l1, l2;
    l1.head(l1, 5);
    cout<< "l1 :";
    l1.print(l1);
    l2.head(l2, 5);
    cout<< "l2 :";
    l2.print(l2);
    find_same(l1, l2);
    cout<< endl;
}

