// 归并排序

#include <iostream>
#include <vector>
using namespace std;

void merge(int *a, int m, int L, int R)
{
    int help[R - L + 1] = {0};
    int i = L;
    int j = m + 1;
    int index = 0;
    while (i <= m && j < R + 1)
    {
        if(a[i] < a[j])
        {
            help[index++] = a[i++];
        }
        else {
            help[index++] = a[j++];
        }
    }
    while(i <= m)
        help[index++] = a[i++];
    while (j < R+1)
        help[index++] = a[j++];
    for(int t = 0; t< R-L+1; t++)
    {
        a[L++] = help[t];
    }
}

void merge_sort(int *a, int begin, int end)
{
    if(begin == end)
        return;
    int middle = (end + begin) / 2;
    merge_sort(a, begin, middle);
    merge_sort(a, middle+1, end);
    merge(a, middle, begin, end);
}

int main()
{
    int a[] = {1, 3, 4, 2, 5};
    merge_sort(a ,0, 4);
//    for(int i = 0; i<5; i++)
//        cout<< a[i]<<" ";
//    cout<< endl;

}
