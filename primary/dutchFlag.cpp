//
// Created by Dawn on 18-5-2.
//
/*
 * 荷兰国旗问题
 * 时间复杂度O(N)
 */

#include <iostream>
#include "base.cpp"
using namespace std;

void sort(int *a, int L, int R, int n)
{
   int i = L + 1;
   while (i < R)
   {
       if(a[i] < n)
       {
           swap(a, i++, ++L);
       }
       else if(a[i] == n)
       {
           i++;
       }
       else
       {
           swap(a, i, --R);
       }
   }
}

int main()
{
    int len = 10;
    int a[len] = {0};
    int Lmargin = 0;
    int Rmargin = len-1;
    int n;
    random(a, len);
    cout<< " The orgin array is :"<< endl;
    print(a, len);
    cout << " The number is: "<< endl;
    cin >> n;
    sort(a, Lmargin-1, Rmargin+1, n);
    cout<< " The result is: "<< endl;
    print(a, len);
}

