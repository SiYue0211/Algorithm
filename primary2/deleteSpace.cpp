/*
 * Created by dawn on 18-7-10.
 * 题目描述：给一个字符串，大小写字母和数字和空格，空格不会连续，要求去掉字母和字母或者数字和数字间的空格，所有字母变为小写
 *    来源：京东面经
*/

#include <iostream>
#include <string>
using namespace std;

void del_space(string &str){
    int length = str.size();
    int new_length = 0;
    int gap = 'a' - 'A';
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + gap;
    }
    for (int i = 0; i < length; ++i) {
        if(str[i] == ' ' && i != 0 && i + 1 < length){
            if((str[i-1] >= 'a' && str[i-1] <= 'z' &&
                str[i+1] >= 'a' && str[i+1] <= 'z') ||
               (str[i-1] >= '0' && str[i-1] <= '9' &&
                str[i+1] >= '0' && str[i+1] <= '9')){
                continue;
            }
            else{
               str[index++] = ' ';
            }
        }
        else
            str[index++] = str[i];
    }
    str = str.substr(0, index);

}

int main(){
    string str = "Ab A 1 1 b A e R";
    del_space(str);
    cout<< str<< endl;
}