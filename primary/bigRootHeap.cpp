//
// Created by Dawn on 2018/5/3.
//
/*
 * 大根堆
 * 建立大根堆复杂度O(N)
 * 思路：
 * ----从根节点开始，如果一个结点大于父节点的值，那么这个结点和父节点进行交换。
 * ----在向上进行比较。
 */

#include <iostream>
#include <iomanip>
using namespace std;

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

//void sort(int *a, int len)
//{
//    for(int i=1; i<len; i++)
//    {
//        int j = (i - 1) / 2;
//        bool mark = false;
//        while (1)
//        {
//            if (j == 0)
//                mark = true;
//            if (i == 0)
//                break;
//            if (a[i] >= a[j])
//            {
//                swap(a, i, j);
//                i = j;
//                j = (i - 1) / 2;
//            }
//            else if(a[i] < a[j] || mark == true)
//                break;
//        }
//    }
//}

// 别人的方法更加简洁
void sort(int *a, int len)
{
    for(int i=0; i<len; i++)
    {
        while(a[i] > a[(i-1)/2])
        {
            swap(a, i, (i-1)/2);
            i = (i - 1) / 2;
        }
    }
}

int main()
{
    int a[6] = {2, 1, 3, 6, 0, 4};
    sort(a, 6);
    for(int i=0; i<6; i++)
        cout << setw(6) << a[i];
}