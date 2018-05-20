/*
 * Created by dawn on 18-5-20.
 * 题目描述：在行列都排列好的矩阵中找数
 *         给定一个由N×M的整数矩阵，和一个整数k
 *         矩阵的每一行和每一列都是排好序的，实现一个函数
 *         判断k是否在矩阵中
 *         要求实践复杂度O(n+m),额外空间复杂度O(1)
*/

#include <iostream>
using namespace std;

bool find(int a[3][4], int k)
{
    int max_i = 2, max_j = 3;
    int i = 0, j = max_j;
    while(i >=0 && j >= 0)
    {
        while (a[i][j] > k && j >= 0)
            j--;
        while (a[i][j] < k && i <= max_i)
        {
            i++;
        }
        if(a[i][j] == k)
            return true;
        else
            j--;
    }
    return false;
}

int main()
{
    int a[3][4] = {{1, 2, 5, 6},
                   {2, 5, 7, 9},
                   {4, 6, 8, 10}};
    int k;
    cin >> k;
    int result = find(a, k);
    cout<< result<< endl;
}

