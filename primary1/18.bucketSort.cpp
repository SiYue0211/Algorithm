/*
 * Created by Dawn on 2018/5/6.
 * 桶排序包括计数排序和基数排序，是一种非基于比较的排序。
 * 时间复杂度为O(N), 额外空间复杂度O(N),是一种稳定的排序
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> bucket(std::vector<int> a)
{
    int max = -1;
    for(int i=0; i<a.size(); i++)
        if(a[i] > max)
            max = a[i];
    std::vector<int> t(max+1, 0);
    for(int i=0; i<a.size(); i++)
        t[a[i]]++;
    for(int i=0, j=0; i<t.size();i++)
    {
        while (t[i]-- > 0)
            a[j++] = i;
    }
    return a;
}

int main()
{
    std::vector<int> a;
    for(int i = 1; i<10; i++)
        a.push_back(i);
    std::random_shuffle(a.begin(), a.end());
    std::vector<int>::iterator it;
    for(it=a.begin(); it!=a.end(); it++)
        std::cout<< *it<< "  ";
    std::cout<< std::endl;
    a = bucket(a);
    for(it=a.begin(); it!=a.end(); it++)
        std::cout<< *it<< "  ";
    std::cout<< std::endl;

}

