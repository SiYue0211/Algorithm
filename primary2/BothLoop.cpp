/*
 * Created by dawn on 18-5-29.
 * 原题目：在本题中，单链表可能有环， 可也可能没环。给定两个单链表的头结点head1和head2。这两个链表可能相交
 *        也可能不想交。请实现一个函数，如果两个链表相交，请返回相交的第一个节点; 如果不想交，返回null即可。
 *        要求：如果链表1的长度为N，链表2的长度为M，时间复杂度达到O(N+M)。额外空间复杂度。
 * 两个个有环链表是否有交点，如果有返回第一个交点，没有返回null
 *
 * 思路：
 *      1.先判断这个单链表是否有环， 如果有环，则返回进入环的结点，如果没有环，返回空
 *        做法：用两个指针，一个快指针，一个慢指针，快指针一次走两步，慢指针一次走一步。当快指针追上慢指针说明有环。
 *             如果快指针遇到空，则返回null，其含义为单链表。
 *             然后将快指针的指针指向头结点（这个头结点是指头没有数据的那个结点），快指针一次变成走一步，慢指针依然
 *             一次走一步。他们相遇的结点就是入环的结点。返回即可。
 *        具体代码写在leetcode上。
 *      2. 如果判断是无环单链表
 *          做法：遍历两个单链表，记录两个单链表的长度和他们的尾指针。
 *               将长度大的链表先走，走到他们平齐，然后一起走，比较结点是否相同，相同的话返回。
 *         如果判断是有环单链表，分为3种情况：
 *         情况1：他们两个入环结点相同，直接返回这个结点。
 *         情况2：他们两个入环结点不同，则从第一个单链表的入环结点开始往下走，如果直到回到第一个单链表的入环结点都没有
 *               遇到第二个单链表的入环结点，那么说明这两个链表彼此独立，没有交。否则返回两个入环结点中任意一个结点。
 * 由于判断单链表是否有环，并返回入环结点。我在leetcode已经写了，不再继续写。
 * 判断单链表是否有交点也在leetcode上写了。
 * 下面的代码是有环链表是否有交。
 * 自己写测试用例太费劲了。
*/
#include <iostream>
using namespace std;

struct NodeList{
    int val;
    NodeList *next;
};

NodeList * find_same_node(NodeList *headA, NodeList *headB)
{
    if(headA == headB)
        return headA;
    NodeList *p = headA->next;
    while(p != headA)
    {
        if(p == headB)
            return headB;
        p = p->next;
    }
    return nullptr;
}



int main()
{
    NodeList *a_1= new NodeList;
    a_1->val = 1;
    NodeList *a_2 = new NodeList;
    a_2->val = 2;
    NodeList *a_3 = new NodeList;
    a_3->val = 3;
    NodeList *a_4 = new NodeList;
    a_4->val = 4;
    NodeList *a_5 = new NodeList;
    a_5->val = 5;
    NodeList *a_6 = new NodeList;
    a_6->val = 6;

    a_1->next = a_2;
    a_2->next = a_3;
    a_3->next = a_4;
    a_4->next = a_5;
    a_5->next = a_6;
    a_6->next = a_3;

    NodeList *b_1 = a_5;
//    NodeList *b_1= new NodeList;
//    b_1->val = 1;
//    NodeList *b_2 = new NodeList;
//    b_2->val = 2;
//    NodeList *b_3 = new NodeList;
//    b_3->val = 3;
//    NodeList *b_4 = new NodeList;
//    b_4->val = 4;
//    NodeList *b_5 = new NodeList;
//    b_5->val = 5;
//    NodeList *b_6 = new NodeList;
//    b_6->val = 1;
//    NodeList *b_3 = a_3;
//
//    b_1->next = b_2;
//    b_2->next = b_3;

//    b_3->next = b_4;
//    b_4->next = b_5;
//    b_5->next = b_6;
//    b_6->next = b_1;

    NodeList *result = find_same_node(a_3, b_1);
    if(result == nullptr)
        cout<< "NULL"<< endl;
    else
        cout<< result->val<< endl;
   }