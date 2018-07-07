/*
 * Created by dawn on 18-7-7.
 * 大疆笔试题：给定一个长度为n的数组和一个整数M，在这个数组里选择三个数，三个数的和小于M，返回有多少种方法，并写出
 *          时间复杂度
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal_count(vector<int> &array, int M){
    sort(array.begin(), array.end());
//    for (int l = 0; l < array.size() ; ++l) {
//        cout<< array[l]<< " ";
//    }
//    cout<< endl;
    vector<int> dup(array.size(), 0);
    for (int j = 1; j < dup.size(); ++j) {
        if(array[j] == array[j-1])
            dup[j] = dup[j-1] + 1;
        else
            dup[j] = dup[j-1];
    }
//    for (int k = 0; k < dup.size(); ++k) {
//        cout<< dup[k] << " ";
//    }
//    cout<< endl;
    int count = 0;
    for (int i = 0; i < array.size()-2; ++i) {
        if(i > 0 && array[i] == array[i-1])
            continue;
        int L = i + 1;
        int R = array.size() - 1;
        while(L < R){
            if(array[L] == array[L-1] && L != i+1){
                L++;
                continue;
            }
            int cur_sum = array[i] + array[L] + array[R];
            if(cur_sum <= M){
//                count = count + R - L;
                cout<< L << " "<< R<< endl;
                count = count + R - L - (dup[R] - dup[L]);
                if(array[L] == array[L+1])
                    count++;
                L++;
                cout<< count<< endl;
            }
            else
                R--;
        }

    }
    return count;
}

int main(){
    vector<int> array = {3,2,5,2,1,4,2,3};
    int M = 10;
    int result = cal_count(array, M);
    cout<< result<< endl;
}

