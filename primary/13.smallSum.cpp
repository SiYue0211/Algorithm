//
// Created by Dawn on 2018/4/26.
//
// 小和问题
// 问题描述：在一个数组里，每一个数的左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和
//    例子：
//    [1, 3, 4, 2, 5]
//    1 左边比1小的数，没有
//    3 左边比3小的数，1
//    4 左边比4小的数，1，3
//    2 左边比2小的数，1
//    5 左边比5小的数，1，3，4，2

/*
 * 解题思路：
 * 1. 暴力求解，这个很容易想到，但是时间复杂度太高
 * 2. 用归并的思想
 * ------再归并中，将两个已经排好序的数组进行外排
 * ------如果左边数组的值大于右边数组的值，说明，右边数组的所有值均大于左边数组的当前值，于是用右面数组的位数乘以左边的当前值，累加到总小和里。
 */
#include <iostream>
#include "base.cpp"
using namespace std;

int sum = 0;

void merge(int *a, int M, int L, int R)
{
    int help[R-L+1] = {0};
    int i = L;
    int j = M+1;
    int ind = 0;
    while(i <= M && j <= R)
    {
        if(a[i] < a[j])
        {
            help[ind++] = a[i];
            int num = R - j + 1;
            sum += num * a[i];
            i++;
        }

        else
            help[ind++] = a[j++];
    }
    while (i <= M)
    {
        help[ind++] = a[i++];
    }
    while (j <= R)
    {
        help[ind++] = a[j++];
    }
    for(int i=0; i<R-L+1; i++)
        a[L+i] = help[i];

}

void MergeSort(int *a, int L, int R)
{
    if(L == R)
        return;
    int Mid = L + ((R - L) >> 1); // 用位运算比常数运算快
    MergeSort(a, L, Mid);
    MergeSort(a, Mid+1, R);
    merge(a, Mid, L, R);
}

int main()
{
    int len = 10;
    int a[len] ={0};
    random(a, len);
    print(a, len);
    MergeSort(a, 0, len-1);
    print(a, len);
    cout << sum << endl;
}