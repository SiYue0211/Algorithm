/*
 * Created by dawn on 18-6-18.
 * 题目要求：n的阶乘
*/

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}

int main(){
    int n = 5;
    int result = factorial(n);
    cout<< result<< endl;
}

