//
// 对数器 ：
// 1. 有一个你要测试的方法
// 2. 有一个你能实现的但是时间复杂度不符合题目要求的算法
// 3. 实现一个你能实现的但是时间复杂度符合要求的算法
// 4. 用一个随机样本产生器产生大量样本
// 5. 通过比对2方法和3方法看是否出错
// 6. 如果出错打印，分析原因
// 7. 当多个比对通过，可以认为3正确
// Created by Dawn on 2018/4/22.
//
#include <iostream>
#include "0.base.cpp"
#include <vector>
#include <stdlib.h>
#include <algorithm>


int main()
{
    int testTime = 300;
    int maxSize = 10;
    int maxValue = 100;
    for(int i=0; i<testTime; i++)
    {
        vector<int> A;
        A = generateRandomArray(A, maxSize, maxValue);
        vector<int> OriginA(A);
        vector<int> A_copy(A);
        sort(A.begin(), A.end());
        A_copy = bubble_sort(A_copy, A_copy.size());
        bool isTrue = compare(A, A_copy);
        if(isTrue == false)
            printVector(OriginA, OriginA.size());
    }

}
