//
// Created by Dawn on 2018/5/2.
//
/*
 * 采用荷兰旗的思路
 */

#include <iostream>
#include "0.base.cpp"
using namespace std;

int partition(int *a, int l, int r)
{
    int less = l - 1;
    int more = r;
    while (l < more)
    {
        if(a[l] < a[r])
            swap(a, ++less, l++);
        else if(a[l] == a[r])
            l++;
        else
            swap(a, --more, l);
    }
    swap(a, r, more);
    return more;


}

void quicksort(int *a, int l, int r)
{
    if(l < r)
    {
        int temp = rand() % (r -l + 1) + l;
        swap(a, r, temp);
        int par = partition(a, l, r);
        quicksort(a, l, par-1);
        quicksort(a, par+1, r);
    }

}

int main()
{
    int len = 10;
    int a[len] = {0};
    random(a, len);
    cout << "The origin array is:" << endl;
    print(a, len);
    cout << "The result array is:" << endl;
    quicksort(a, 0, len-1);
    print(a, len);
}
