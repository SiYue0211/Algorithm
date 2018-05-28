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

#include <iostream>
using namespace std;
int small_sum = 0;

void merge(int *a, int begin, int middle, int end)
{
    int help[end-begin+1] = {0};
    int i = begin;
    int j = middle + 1;
    int index = 0;
    while(i <= middle && j <= end)
    {
        if(a[i] < a[j])
        {
            small_sum += ((end - j + 1) * a[i]);
            help[index++] = a[i++];
        }
        else{
            help[index++] = a[j++];
        }
    }
    while(i <= middle)
        help[index++] = a[i++];
    while(j <= end)
        help[index++] = a[j++];

    for(int i=0; i<end-begin+1; i++)
        a[begin+i] = help[i];

}

void merge_sort(int *a, int begin, int end)
{
    if (begin == end)
        return;
    int middle = (begin + end) / 2;
    merge_sort(a, begin, middle);
    merge_sort(a, middle+1, end);
    merge(a, begin, middle, end);
}

int main()
{
    int a[] = {1, 3, 4, 2, 5};
    merge_sort(a, 0, 4);
    for(int i=0; i<5; i++)
        cout<< a[i]<< " ";
    cout<< endl;
    cout<< "small sum:  "<<small_sum<< endl;
}