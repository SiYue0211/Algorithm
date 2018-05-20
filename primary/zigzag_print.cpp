/*
 * Created by dawn on 18-5-20.
 * 之字型打印矩阵， 额外空间复杂度O(1)
 * 思路： 设置两个点，P, Q。 初始两个点都指向左上点，终止都指向右下点
 *       P的路径是一直向右移动，直到到边界位置，开始向下移动
 *       Q的路径是一直向下移动，直到到边界位置，开始向右移动
 *       每次打印P，Q之间的数据。具体从P到Q还是从Q到P用一个bool值限定
 *       如果一次是从P到Q， 第二次从Q到P
*/

#include <iostream>
using namespace std;

void zigzagPrint(int a[3][3], int height, int width)
{
    int p_x = 0;
    int p_y = -1;
    int q_x = -1;
    int q_y = 0;
    int total_step = height * width;
    int index = 0;
    bool isBottom2Up = true;
    while(index < total_step){
        if(p_y < width-1)
            p_y++;
        else if (p_y == width-1)
            p_x++;
        if (q_x < height-1)
            q_x++;
        else if(q_x == height-1)
            q_y++;
        if(isBottom2Up){
            for (int i = q_x, j = q_y; i >= p_x && j <= p_y ; --i, ++j) {
                cout<< a[i][j]<< " ";
        }}
        else{
            for (int i = p_x, j = p_y; i <= q_x && j >= q_y ; ++i, --j) {
                cout<< a[i][j]<< " ";
            }
        }
        if(isBottom2Up)
            isBottom2Up = false;
        else
            isBottom2Up = true;
        index += 1;
    }

}

int main()
{
    int a[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    zigzagPrint(a, 3, 3);
}

