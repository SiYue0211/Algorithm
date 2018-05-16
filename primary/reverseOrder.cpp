//
// Created by Dawn on 2018/4/27.
//
/*
 * 逆序对问题：
 * ---问题描述：
 * ------在一个数组里，左边的数如果比右边的数大，则两个数构成一个逆序对，打印所有逆序对
 * ---思路：
 * ------利用归并排序的思想，但是这次是从大往小排，如果左侧数组元素大于右侧数组，说明左侧数组中该元素大于右侧数组至此开始所有元素，打印出就OK
 */

#include <iostream>
#include "base.cpp"
using namespace std;

void merge(int *a, int M, int L, int R)
{
    int help[R-L+1] = {0};
    int i = L;
    int j = M+1;
    int idx = 0;
    while(i<=M && j<=R)
    {
        if(a[i] <= a[j])
            help[idx++] = a[j++];
        else
        {
            for(int t=j; t<=R; t++)
            {
                cout<< "(" << a[i] << "," << a[t] << ')'<<endl;
            }

            help[idx++] = a[i++];
        }
    }
    while (i <= M)
        help[idx++] = a[i++];
    while (j <= R)
        help[idx++] = a[j++];
    for(int i =0 ;i<R-L+1; i++)
    {
        a[L+i] = help[i];
    }

}
void mergeSort(int *a, int L, int R)
{
    if (L == R)
        return;
//    int M = L + ((R - L) >> 1);
    int M = (L + R) /2;
    mergeSort(a, L, M);
    mergeSort(a, M+1, R);
    merge(a, M, L, R);
}

int main()
{
    int len = 10;
    int a[len] = {0};
    random(a, len);
    print(a, len);
    mergeSort(a, 0, len-1);
}