//
// Created by Dawn on 18-5-2.
//
/*
 * 给定一个数组和一个数num，请将小于等于num的数放在数组左边，大于数组的数放在数组右边
 * 要求： 时间复杂度O(N)
 */
#include <iostream>
#include "0.base.cpp"
using namespace std;

void sort(int *a, int L, int R, int n)
{
    int Lmargin = L;
    for(int i=L+1; i<R-L-1; i++)
    {
        if(a[i] <= n)
        {
            swap(a, i, ++Lmargin);
        }
    }
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
    cout << "Please enter the number: "<< endl;
    cin >> n;
    cout << "The result array is :"<< endl;
    sort(a, Lmargin-1, Rmargin+1, n);
    print(a, len);

}
