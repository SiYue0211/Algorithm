/*
 * Created by dawn on 18-6-18.
 * 题目描述：母牛每年生一只小牛，新出生的母牛成长三年后也能每年生一只母牛，假设不会死，求N年后，一共有多少母牛
*/

#include <iostream>
using namespace std;

int cal_cow(int n){
    if(n <= 4)
        return n;
    else
        return cal_cow(n-1) + cal_cow(n-3);
}

int main(){
    int n = 7;
    int result = cal_cow(n);
    cout<< result<< endl;
}