/*
 * Created by Dawn on 18-05-09
 * 问题描述：
 * --------给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O（N）
 * --------且要求不能用非基于比较的排序
 */

#include <iostream>
#include <vector>
#include "0.base.cpp"
#include <algorithm>
using namespace std;

int findMax(vector<int> a)
{
    vector<int>::iterator it = a.begin();
    int max = *it;
    for( ; it!=a.end(); it++)
    {
        if(*it > max)
            max = *it;
    }
    return max;
}

int findMin(vector<int> a)
{
    vector<int>::iterator it = a.begin();
    int min = *it;
    for( ; it!=a.end(); it++)
    {
        if(*it < min)
            min = *it;
    }
    return min;
}

void findMaxDifference(vector<int> a)
{
    int max = findMax(a);
    int min = findMin(a);
    auto len = a.size();
    auto arrayLength = a.size() + 1;
    vector<int> markMax(arrayLength);
    vector<int> markMin(arrayLength);
    vector<bool> markExist(arrayLength, false);
    for(auto i: a)
    {
        int index = int((float(i - min) / float(max - min)) * float(len));
        if(markExist[index] == true)
        {
            if(i > markMax[index])
            {
                markMax[index] = i;
            }

            if(i < markMin[index])
            {
                markMin[index] = i;
            }
        }
        else
        {
            markMax[index] = i;
            markMin[index] = i;
            markExist[index] = true;
        }
    }
    int result = 0;
    int i = 0;
    while(i < len)
    {
        int j = i+1;
        while(markExist[j] == false && j<arrayLength)
        {
            j++;
        }
        if(j == arrayLength-1)
            break;
        int resultMin = markMax[i];
        int resultMax = markMin[j];
        int max_minus_min = resultMax - resultMin;
        if(max_minus_min > result)
            result = max_minus_min;
        i = j;
    }
    cout<< "result: "<< result<< endl;
}

int main()
{
    vector<int> a;
    int arrayLen = 20;
    int arrayMaxValue = 100;
    a = generateRandomArray(a, arrayLen, arrayMaxValue);
    printVector(a, arrayLen);

    findMaxDifference(a);

    sort(a.begin(),a.end());
    printVector(a, arrayLen);




}
