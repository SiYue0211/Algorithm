/*
 * Created by Dawn on 2018/6/20.
 * 给定数字n，打印从1到最大的n位十进制数
*/
#include <iostream>
#include <string>
using namespace std;

void print_num(int n){
    string num(n, '0');
    string max_num(n, '9');

    while(num != max_num){
        for (int i = n-1; i >=0 ; i--) {
            if(num != max_num){
                if(num[i] != '9'){
                    num[i] += 1;
                    cout<< num<< endl;
                    break;
                }
                if(num[i] == '9' && i != 0)
                    num[i] = '0';
            }
        }
    }

}


int main(){
    int n = 3;
    print_num(n);


}

