/*
 * Created by dawn on 18-6-18.
 * 题目要求:字符串全排列
*/

#include <iostream>
#include <string>
using namespace std;

void swap(string &str, int i, int j)
{
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
}

void print_full(string str, int begin, int end){
   if(begin == end)
       cout<< str<< endl;
   else{
       for (int i = begin; i <= end; ++i) {
           swap(str, i, begin);
           print_full(str, begin+1, end);
           swap(str, i, begin);
       }
   }
}

int main(){
    string str = "1234";
    print_full(str, 0, 3);
}

