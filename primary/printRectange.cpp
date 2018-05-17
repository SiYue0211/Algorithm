/*
 * Created by dawn on 18-5-17.
 * 转圈打印矩阵（测试过程序，正方形或长方形都可以正常运行）
*/

#include <iostream>
using namespace std;

void printRec(int a[2][2], int lx, int ly, int rx, int ry)
{
    while(lx < rx && ly < ry)
    {
        int i = lx;
        int j = ly;
        while(j < rx)
            cout<< a[i][j++]<< " ";
        while(i < ry)
            cout<< a[i++][j]<< " ";
        while(j > lx)
            cout<< a[i][j--]<< " ";
        while(i > ly)
            cout<< a[i--][j]<< " ";
        lx++;
        ly++;
        rx--;
        ry--;
    }
    if (lx == rx && ly == ry)
        cout<< a[ly][lx] << " ";
    else
    {
        if(lx == rx)
        {
            for(int i=ly; i<=ry; i++)
                cout<< a[i][lx]<< " ";
        }
        if(ly == ry)
        {
            for(int i=lx; i<=rx; i++)
                cout<< a[ly][i]<< " ";
        }
    }
}

int main()
{

    int a[2][2] = {{1, 2}, {3, 4}};
    printRec(a, 0, 0, 1, 1);
}
