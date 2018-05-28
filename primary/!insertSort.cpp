//
// 插入排序思路：
// 首先对数组中前两个数据进行排序，如果a[1] < a[0]为真，则进行交换
// 再对数组中前三个数据进行排序， 如果a[2] < a[1] 为真则进行交换，再对a[1] < a[0]进行判断，如果真， 则交换
// 依次类推
// 时间复杂度O(n²)
// Created by Dawn on 2018/4/22.
//

#include <iostream>
#include "0.base.cpp"
int len = 10;

void insertSort(int a[], int len)
{
    if(len ==0 || len<2)
        return;
//    for(int i=1; i<len; i++)
//    {
//        int mark = i;
//        for(int j=i-1; j>=0; j--)
//        {
//            if(a[mark] < a[j])
//            {
//                swap(a, mark, j);
//                mark = j;
//            }
//
//            else
//                break;
//        }
//    }
    //这个循环看起来更加简洁
    for(int i=1; i<len; i++)
    {
        for(int j=i-1; j>=0 && a[j]>a[j+1]; j--)
            swap(a, j, j+1);
    }
}
int main()
{
    int A[len] = {0};
    random(A, len);
    print(A, len);
    insertSort(A, len);
    print(A, len);
    return 0;

}

