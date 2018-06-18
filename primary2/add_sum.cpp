/*
 * Created by Dawn on 2018/6/18.
 * 题目描述：给你一个数组arr和一个整数aim，如果可以选择arr中的数组，能不能累加到aim，返回true or false
*/

#include <iostream>
using namespace std;

bool isOK(int *a, int aim, int length, int begin, int num){
    if(begin == length-1)
        return num == aim;
    bool case1 = isOK(a, aim, length, begin+1, num);
    bool case2 = isOK(a, aim, length, begin+1, num+a[begin]);
    return case1||case2;
}

int main(){
    int a[] = {3, 2, 7, 13};
    int length = 4;
    int aim = 9;
    bool result = isOK(a, aim, length, 0, 0);
    cout<< result<< endl;
}

