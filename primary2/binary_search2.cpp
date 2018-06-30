/*
 * Created by Dawn on 2018/6/19.
 * 二分查找
*/
#include <iostream>
using namespace std;

int BinarySearch(int *a, int len, int value){
    int low = 0;
    int high = len;
    while (low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == value)
            return mid;
        else if(a[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int len = 10;
    int arr[len];
    for (int i = 0; i < len ; ++i) {
        arr[i] = i * 2;
    }
    int find_num = 6;
    int result = BinarySearch(arr, len-1, find_num);
    cout<< result<< endl;
}
