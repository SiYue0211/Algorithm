/*
 * Created by dawn on 18-6-30.
 * 题目要求：把n个骰子丢在地上，所有骰子朝上一面的点数之和为s，输入n，打印出s的所有可能值出现的概率
*/

#include <iostream>
#include <vector>
using namespace std;

void cal_prob(vector<int> &prob, int index){
    prob[index] = 0;
    for(int i = index-1; i >= index-6 && i >= 0; i--)
        prob[index] += prob[i];
}

void problity(int num, int sum){
    // num骰子的数量， sum骰子和
    if(num < 1)
        return;
    vector<int> prob(num*6+1, 0);
    // 第一次投掷骰子
    for (int i = 1; i < 7; ++i) {
        prob[i] = 1;
    }
    while(--num){
        for (int i = sum; i >= 0; --i) {
            cal_prob(prob, i);
        }
    }
    cout<< prob[sum]<< endl;
}

int main(){
    problity(3, 18);
}