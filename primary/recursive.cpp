//
// 这个程序简单的用递归的思想求得了数组的最大值
// Created by Dawn on 2018/4/25.
//
#include <iostream>
using namespace std;
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int MaxArray(int a[], int L, int R)
{
    if(L == R)
        return a[L];
    int mid = (L + R) / 2;
    int maxL = MaxArray(a, L, mid);
    int maxR = MaxArray(a, mid+1, R);
    return max(maxL, maxR);
}
int main()
{
    int a[]={5, 1, 9, 0};
    int maxNum = MaxArray(a, 0, 3);
    cout << maxNum;
}