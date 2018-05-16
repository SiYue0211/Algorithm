/*
 * Created by Dawn on 18-5-4.
 * 堆排序
 * 思路：如果要从小到大排序，首先要建立一个大根堆。然后将大根堆的第一个元素和最后一个元素进行交换
 *      如此这样，数组中最后一位就是整个数组的最大值，在之后的排序不再考虑这个位置（最后一位），因为它已经排好序了。
 *      对数组第一位到倒数第二位进行heapify也就是调整堆。调整堆之后数组的第一位就是次大值，将其交换到倒数第二位，
 *      并认为它已经排好序，不再对其进行排序。重复，直到数组长度等于0.
 * 建立大根堆的思路：
 *      首先处理数组的前两个元素将指针指向第二个元素，如果其大于其父结点，则进行交换，并将指针指向其父结点并重复过程，
 *      直到不大于父结点，退出。
 *      再将第三个元素加入进来，将指针指向第三个元素，重复上述过程。
 * 调整堆思路：
 *      调整堆的规则是从根结点开始，将指针指向根结点，看根节点的左右两个结点哪个大，然后再用大的结点值和根结点进行比较，
 *      如果大于根结点则置换。并将指针指向大的结点位置，重复上述过程，直到某个结点的左结点超出范围（数组的长度）。
 *
 */

#include <iostream>
#include "base.cpp"
#include <iomanip>
using namespace std;


void buildHeap(int *a, int index)
{
    while (a[index] > a[(index - 1) / 2])
    {
        swap(a, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapify(int *a, int index, int len)
{
    int left = index * 2 + 1;
    while (left < len)
    {
        int right = left + 1;
        int max;
        if(right >= len)
            max = left;
        else
        {
            max = a[left] > a[right] ? left: right;
        }
        if(a[max] > a[index])
        {
            swap(a, max, index);
            index = max;
            left = index * 2 + 1;
        }
        else
            break;

    }
}

int main()
{
    int len = 10;
    int copy_len = len;
    int a[len] = {0};
    random(a, len);
    print(a, len);
    for(int i=1; i<len; i++)
    {
        buildHeap(a, i);
    }
    swap(a, 0, --copy_len);
    while(copy_len > 0)
    {
        heapify(a, 0, copy_len);
        swap(a, 0, --copy_len);
    }

    for(int i= 0; i<len; i++)
        cout<< setw(6)<< a[i];
    cout<< endl;

}

