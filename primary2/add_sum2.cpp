/*
 * Created by Dawn on 2018/6/18.
 * 题目描述：给你一个数组arr和一个整数aim，如果可以选择arr中的数组，能不能累加到aim，返回true or false
*/

#include <iostream>
using namespace std;


int main(){
    int a[] = {3, 2, 7, 13};
    int sum = 0;
    int length = 4;
    int aim = 18;
    for (int i = 0; i < length; ++i) {
        sum += a[i];
    }
    sum++;
    cout<<sum<<endl;
    bool result[length+1][sum];
    for (int i = 0; i < sum; ++i) {
        if(i == aim)
            result[length][i] = true;
        else
            result[length][i] = false;
    }
    for (int i = length-1; i >=0 ; --i) {
        for (int j = 0; j < sum; ++j) {
            bool t;
            if(j+a[i] > sum)
                t = false;
            else
                t = result[i+1][j+a[i]];
            result[i][j] = result[i+1][j] || t ;
        }
    }
    cout<<result[0][0]<< endl;
}

