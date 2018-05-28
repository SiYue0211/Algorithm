
#include <iostream>
using namespace std;

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void build_heap(int *a, int len)
{
    for (int i = 0; i < len; ++i) {
        while (a[i] > a[(i-1)/2])
        {
            swap(a, i, (i-1)/2);
            i = (i - 1) / 2;
        }
    }
}

void sort(int *a, int len)
{
    for (int i = len-1; i > 0 ; --i) {
        swap(a, 0, i);
        int mark = 0;
        int temp = mark * 2 + 1;
        while(temp < i)
        {
            int max_index;
            if(temp+1 < i)
            {
                max_index = a[temp] > a[temp+1] ? temp : temp + 1;
            }
            else
            {
                max_index = temp;
            }
            if(a[max_index] > a[mark])
            {
                swap(a, max_index, mark);
                temp = max_index *2 + 1;
                mark = max_index;
            }
        }
    }
}

int main()
{
    int a[] = {3, 5, 1, 2, -1, 9, 0};
    build_heap(a, 7);
    sort(a, 7);
    for(int i=0; i<7; i++)
        cout<< a[i]<< " ";
    cout<< endl;
}