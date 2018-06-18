/*
 * Created by dawn on 18-6-15.
 * 给定一个字符串类型的数组strs， 找到一种拼接方式， 使得把所有字符串拼起来之后形成的字符串具有最低的字典序。
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2){
    return s1+s2 < s2+s1;
}

int main()
{
    string str[5] = {"ab", "a", "ba", "ca", "ac"};
    sort(str, str+5, compare);
    for(int i = 0; i < 5; i++)
        cout<< str[i];
    cout<< endl;
}

