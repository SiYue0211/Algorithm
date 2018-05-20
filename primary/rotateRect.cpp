/*
 * Created by dawn on 18-5-18.
 * 题目要求：给定一个整形正方形矩阵，请将该矩阵调成顺时针旋转90度的样子。
 * 额外空间复杂度: O(1)
 *
*/

#include <iostream>
using namespace std;

void rotate_rect(int a[4][4], int length)
{
    int up = 0;
    int bottom = length - 1;
    while (up < bottom)
    {
        int t = 0;
        while(t < bottom - up)
        {
            int temp0;
            int temp1;
            int temp2;
            temp0 = a[up+t][bottom];
            a[up+t][bottom] = a[up][up+t];
            temp1 = a[bottom][bottom-t];
            a[bottom][bottom-t] = temp0;
            temp2 = a[bottom-t][up];
            a[bottom-t][up] = temp1;
            a[up][up+t] = temp2;
            t++;
        }
        up++;
        bottom--;
    }
}

int main()
{
    int a[4][4] ={{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};
    rotate_rect(a, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout<< a[i][j]<< " ";
        }
        cout<< endl;
    }
}