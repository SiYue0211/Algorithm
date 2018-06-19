/*
 * Created by Dawn on 2018/6/19.
 * 二分查找
*/
#include <iostream>
using namespace std;

int BinarySearch(int *a, int begin, int end, int value){
    if(begin > end)
        return -1;
    int mid = (begin + end) / 2;
    if(a[mid] == value)
        return mid;
    else if(a[mid] < value){
        BinarySearch(a, mid+1, end, value);
    }
    else
        BinarySearch(a, begin, mid-1, value);
}

int main(){
    int len = 10;
    int arr[len];
    for (int i = 0; i < len ; ++i) {
        arr[i] = i * 2;
    }
    int find_num = 5;
    int result = BinarySearch(arr, 0, len-1, find_num);
    cout<< result<< endl;
}
