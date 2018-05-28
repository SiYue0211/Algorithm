/*
 * Created by dawn on 18-5-22.
 * 题目描述：给定一个单向链表的头结点head，结点值的类型为整形，再给定一个整数pivot。实现一个调整链表的函数
 *         将链表的左部分都是值小于pivot的结点，中间部分都是等于pivot的结点，右部分都是值大于pivot的结点
 *         并且要求在左，中，右三个部分中，与原链表结点的先后次序一致。例如链表9->0->4->5->1,pivot=3
 *         调整后的链表是0->1->9->4->5.
 * 要求：实践复杂度O(N), 额外空间复杂度O(1)
 * 解决思路： 创建三个结点分别是less, equal, more存放整个链表中第一个小于num的结点，第一个等于num的结点，和
 *          第一个大于num的结点。并将这三个点摘出去。然后对于剩余的点，依次遍历，小于num的加入less，等于num的
 *          加入equal, 大于num的加入more。
 *
*/

#include <iostream>
using namespace std;

class Node{
public:
    Node *next;
    int val;
};

class List{
public:
    Node *head;
    void build(List &);
    void print(List &);
};

void List::build(List &l) {
    l.head->val = 0;
    l.head->next = NULL;
    Node * p = l.head;
    int temp;
    while (cin>>temp)
    {
        Node * q = new Node();
        q->val = temp;
        p->next = q;
        p = q;
        p->next = NULL;
    }
}

void List::print(List &l)
{
    Node *p = l.head->next;
    while (p)
    {
        cout<< p->val<< " ";
        p = p->next;
    }
    cout<< endl;
}

void divide(List &l, int num)
{
    if(l.head == NULL || l.head->next == NULL)
        return;
    Node *less = NULL;
    Node *equal = NULL;
    Node *more = NULL;
    int num_l = 0;
    int num_q = 0;
    int num_m = 0;
    Node *pre = l.head;
    Node *p = l.head->next;
    while(p)
    {
        if (p->val < num && num_l == 0)
        {
            less = p;
            pre->next = p->next;
            less->next=NULL;
            num_l++;
            p = pre->next;
        }
        else if(p->val == num && num_q == 0)
        {
            equal = p;
            pre->next = p->next;
            equal->next = NULL;
            num_q++;
            p = pre->next;
        }
        else if(p->val > num && num_m == 0)
        {
            more = p;
            pre->next = p->next;
            more->next = NULL;
            num_m++;
            p = pre->next;
        }
        else{
            pre = p;
            p = p->next;
        }
    }
    p = l.head->next;
    pre = l.head;
    Node * less_end = less;
    Node * equal_end = equal;
    Node * more_end = more;
    while(p)
    {
        if(p->val < num)
        {
            pre->next = p->next;
            less_end->next = p;
            less_end = p;
            less_end->next = NULL;
            p = pre->next;
        }
        else if(p->val == num)
        {
            pre->next = p->next;
            equal_end->next = p;
            equal_end = p;
            equal_end->next = NULL;
            p = pre->next;
        }
        else if(p->val > num)
        {
            pre->next = p->next;
            more_end->next = p;
            more_end = p;
            more_end->next = NULL;
            p = pre->next;
        }
    }
    // 下面这几个条件是为了让程序更加鲁棒
    if(less && equal && more)
    {
        l.head->next = less;
        less_end->next = equal;
        equal_end->next = more;
    }
    else if(less && equal && !more)
    {
        l.head->next = less;
        less_end->next = equal;
    }
    else if (less && !equal && more)
    {
        l.head->next = less;
        less_end->next = more;
    }
    else if(!less && equal && more)
    {
        l.head->next = equal;
        equal_end->next = more;
    }
    else if(less && ! equal && !more)
    {
        l.head->next = less;
    }
    else if(!less && equal && !more)
    {
        l.head->next = equal;
    }
    else if(!less && !equal && more)
    {
        l.head->next = more;
    }

}

int main()
{
    List l;
    l.build(l);
    l.print(l);
    divide(l, 3);
    l.print(l);
}


