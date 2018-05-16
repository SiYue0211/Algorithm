//
// 一个有序数组A， 另一个无序数组B， 请打印B中所有不在A中的数， A的数组长度为N， B的数组长度为M
// 思路：先给B进行排序， 对A，B分别创建一个记录位置的标识--a， b。
//       如果A[a]< B[b], a+1
//       如果A[a]== B[b], b+1
//       如果A[a]> B[b]打印，是我们想要的结果
//  注意： 在A进行全部遍历之后， B可能并完全遍历， 也就是说A的最大值比B中的某个值要小，此时我们要将B后面的数组内容输出
// Created by Dawn on 2018/4/22.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <time.h>
using namespace std;

int len_A = 10;
int len_B = 10;

void random(int a[], int n)
{
    int i = 0;
    while(i<n)
    {
        a[i++] = rand()%100;
    }
}

void print(int a[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout<< setw(10) << a[i];
    cout << endl;
}

int main()
{
    int A[len_A] = {0};
    int B[len_B] = {0};
    int a = 0;
    int b = 0;
    random(A, len_A);
    random(B, len_B);
    sort(A, A+len_A);
    sort(B, B+len_B);
    print(A, len_A);
    print(B, len_B);
    while(b < 10 && a < 10)
    {
        if(A[a] < B[b])
            a++;
        else if(A[a] == B[b])
            b++;
        else
        {
            cout << setw(10) << B[b];
            b++;
        }
    }
    if (a==len_A && b<len_B)
    {
        for(int i=b; i<len_B; i++)
        {
            cout << setw(10) << B[i];
        }
    }
    return 0;
}
