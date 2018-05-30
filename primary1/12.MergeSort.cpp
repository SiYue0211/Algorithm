// 归并排序
// 这个归并排序采用了递归的思想，将一个数组分开进行排序，最后再将两个排好的数组进行外排
// Created by Dawn on 2018/4/26.
//

#include <iostream>
#include "0.base.cpp"
using namespace std;

void Merge(int *a, int M, int L, int R)
{
    int b[R-L+1] = {0};
    int mark = 0;
    int i = L, j = M+1;
    while(i <= M && j <= R)
    {
        if(a[i] < a[j])
        {
            b[mark++] = a[i];
            i++;
        }
        else
        {
            b[mark++] = a[j];
            j++;
        }
    }
    while(i <= M)
    {
        b[mark++] = a[i++];
    }
    while(j <= R)
    {
        b[mark++] = a[j++];
    }
    for(int i=0; i < R-L+1; i++)
    {
        a[L+i] = b[i];
    }
}

void mergeSort(int *a, int L, int R)
{
    if(L == R)
        return;
    int mid = (L + R) / 2;
    mergeSort(a, L, mid);
    mergeSort(a, mid+1, R);
    Merge(a, mid, L, R);
}

int main()
{
    int len = 10;
    int a[len] = {0};
    random(a, len);
    cout << "The origin array is :"<< endl;
    print(a, len);
    mergeSort(a, 0, len-1);
    print(a, len);
}