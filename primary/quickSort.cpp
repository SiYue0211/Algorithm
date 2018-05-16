//
// Created by Dawn on 18-5-2.
//
/*
 * 快排
 */
#include <iostream>
#include "base.cpp"
using namespace std;



void quicksort(int *a, int L, int R)
{
    if(L > R)
        return;
    int i = L;
    int j = R;
    int x = a[L];
    while(i < j)
    {
        while (i < j && a[j] >= x)
            j--;
        if(i < j)
            a[i++] = a[j];
        while (i < j && a[i] < x )
            i++;
        if(i < j)
            a[j--] = a[i];
    }
    a[i] = x;
    quicksort(a, L, i-1);
    quicksort(a, i+1, R);
}

int main()
{
    int len = 10;
    int a[len] = {0};
    int n;
    //  使用Lmargin/ Rmargin的目地是可以在一定范围内对数组进行分类
    int Lmargin = 0;
    int Rmargin = len-1;
    random(a, len);
    cout << "The origin array is :"<< endl;
    print(a, len);
    cout << "The result array is :"<< endl;
    quicksort(a, Lmargin, Rmargin);
    print(a, len);

}