//
// 选择排序：
// 思路： 先将定位标识定位到数组第一位，然后从第二位开始和第一位进行比较，如果某一位比第一位标识的数据小，将最小标识换为这个。
//        继续，直到最后一个数据。然后将这个最小的数据和数组的第一位进行交换。
//        第二轮，将数据的第二位标识为最小，然后根据上述的原则从第三位到最后一位中查找最小值，和第二位数据进行交换。
//        以此类推。
// 时间复杂度：O(N²)
// Created by Dawn on 2018/4/22.
//

#include <iostream>
#include "0.base.cpp"
#include <iomanip>
int Len = 10;

void selectionSort(int a[], int len)
{
    if(len == 0 || len < 2 )
        return;
    for(int i=0; i<len; i++)
    {
        int minIdex = i;
        for(int j=i+1; j<len; j++)
        {
            if(a[j] < a[minIdex])
            {
                minIdex = j;
            }
        }
        if(i != minIdex)
        {
            swap(a, i, minIdex);
        }

    }
}

int main()
{
    int A[Len] = {0};
    random(A, Len);
    print(A, Len);
    selectionSort(A, Len);
    print(A, Len);

}

