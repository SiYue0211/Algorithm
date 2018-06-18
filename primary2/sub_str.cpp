/*
 * Created by dawn on 18-6-18.
 * 题目要求：打印一个字符串所有子序列，包括空字符串
*/

#include <iostream>
#include <string>
using namespace std;

void print_sub(string str, string sub, int mark, int num){
    if(mark == num)
    {
        cout<< sub<< endl;
        return;
    }

    else{
        sub[mark] = ' ';
        print_sub(str, sub, ++mark, num);
        mark--;
        sub[mark] = str[mark];
        print_sub(str, sub, ++mark, num);
    }
}

int main(){
    string str = "abc";
    string sub = "abc";
    print_sub(str, sub, 0, 3);
}
