//
// 冒泡排序
// 思路： 对于一个数组进行遍历，先对数组第一位和第二位进行比较， 如果第一位大于第二位内容，交换两者顺序
//        再对第二位第三位的内容进行比较，依次类推，直到倒数第二位内容和倒数第一位内容进行比较。
//        此时我们可以确定，最后一位的值为整个数组最大值
//        于是，我们在下次遍历时只需要从第一位便利到倒数第二位，以此类推，最后整个数组按照从小到大的顺序排列
//        冒泡排序时间复杂度O(n²), 额外空间复杂度O(1)
// Created by Dawn on 2018/4/22.
//

#include <iostream>
#include <iomanip>
int Len = 10;

void random(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        a[i] = rand() % 100;
    }
}

void print(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        std::cout << std::setw(9) << a[i];
    }
    std::cout<< std::endl;
}

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void bubble_sort(int a[], int len)
{
    if(len == 0 || len < 2)
        return;
    for(int length=len; length>=0; length--)
    {
        for(int i=0; i<length; i++)
        {
            if(a[i] > a[i+1])
                swap(a, i, i+1);
        }
    }
}

int main()
{
    int A[Len] = {0};
    random(A, Len);
    print(A, Len);
    bubble_sort(A, Len);
    print(A, Len);

}

