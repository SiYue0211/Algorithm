/*
 * Created by dawn on 18-5-21.
 * 判断一个链表是否为回文结构
 * 题目描述：给定一个链表的头结点head，请判断该链表是否为回文结构。
 *         例如：1-> 2 -> 1 ,返回true
 *         1 -> 2 -> 2, 返回true
 *         15 -> 6 -> 15, 返回true
 * 要求：如果链表长度为N，时间复杂度达到O(N), 额外空间复杂度达到O(1)
 * 思路：定义两个指针，两个个都指向头结点，一个每次走一步，一个每次走两步
 *      当走两步的指针q到尾巴的时候停止，此时慢指针p指向中心，将中心到尾巴结点
 *      逆置。然后定义两个结点，一个指向头，一个指向尾巴，比对。
*/

#include <iostream>
using namespace std;

class node{
public:
    node *next;
    int data;
};

class list{
public:
    node *h;
    void head(list &l, int n);
    void print(list &l);
};

void list::head(list &l, int n) {
    node *p = new node();
    l.h = p;
    p->next = NULL;
    p->data = n;
    for (int i = 0; i < n; ++i) {
        node *q = new node();
        cin >> q->data;
        q->next = l.h->next;
        l.h->next = q;
    }
}

void list::print(list &l) {
    node *p = l.h;
    p = p->next;
    while(p)
    {
        cout<<p->data<< " ";
        p = p->next;
    }
    cout<< endl;
}

node * reverse(node* p, node*q)
{
    node *i = p->next;
    node *j;
    while (i != q)
    {
        j = i->next;
        i->next = p;
        p = i;
        i = j;
    }
    return p;
}

bool pali(list &l)
{
    // p每次走一步， q每次走2步
    node *p = l.h;
    p = p->next;
    node *q = p;
    while(q)
    {
        int num = 2;
        while(num > 0 && q) {
            num -= 1;
            q = q->next;
//            cout<<"q  "<<q->data<< endl;
//            cout<<"num "<< num<< endl;
        }
        if(!q)
        {
            break;
        }
        if(num == 0)
        {
            p = p->next;
//            cout << p->data<< endl;
        }

    }
//    cout << p->data<< endl;


    // 将后半段逆序
    node *middle = p;
    // 经过处理后p指向尾巴
    p = reverse(p, q);
    node *end = p;

    middle->next = NULL;
    node *start1 = l.h->next;
    node *start2 = p;
    while(start1)
    {
        if(start1->data != start2->data)
        {
//            reverse(end, middle->next);
//            end->next = NULL;
            return false;
        }

        else
        {
            start1 = start1->next;
            start2 = start2->next;
        }
    }
//    reverse(end, middle->next);
//    end->next = NULL;

    return true;


}

int main()
{
    list l;
    l.head(l, 2);
    l.print(l);
    bool isPalindrome = pali(l);
    cout<< isPalindrome<< endl;
//    l.print(l);
}






















