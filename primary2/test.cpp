/*
 * Created by dawn on 18-6-5.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int StrToInt(string str) {
    int flag1 = 0;
    int flag2 = 0;
    int num = 0;
    int i = 0;
    int len = str.size();
    //去掉str前面的空字符
    for(; i<len; i++){
        if(str[i] != ' ')
            break;
    }
    if(i == len)
        return 0;
    for(; i<len; i++){
        if(str[i] == '+')
            flag1++;
        else if(str[i] == '-')
            flag2++;
        else
            break;
    }
    if(flag1 + flag2 > 1)
        return 0;
    if(i == len)
        return 0;
    for(; i<len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + str[i] - '0';
            if(flag1 && num > INT_MAX)
                return 0;
            if(flag2 && num < INT_MIN)
                return 0;
        }
        else
            return 0;
    }
    if(flag1 == 1)
        return num;
    if(flag2 == 2)
        return -num;
}
int main()
{
    string a= "abn";
    int result = StrToInt(a);
    cout<< result<< endl;
}