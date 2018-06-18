/*
 * Created by dawn on 18-6-15.
 * 题目要求：一块金条切成两半， 是需要花费和长度数值一样的铜板的。 比如长度为20的金条， 不管切成长度多大的两半， 都要花费20个铜
 *          板。 一群人想整分整块金条， 怎么分最省铜板？
 *          例如,给定数组{10,20,30}， 代表一共三个人， 整块金条长度为10+20+30=60. 金条要分成10,20,30三个部分。
 *          如果， 先把长度60的金条分成10和50， 花费60 再把长度50的金条分成20和30，花费50 一共花费110铜板。
 *          但是如果， 先把长度60的金条分成30和30， 花费60 再把长度30金条分成10和20， 花费30 一共花费90铜板。
 *          输入一个数组，返回分割的最小代价。
 * 思路：哈夫曼编码
 *
*/

#include <iostream>
using namespace std;

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int * create_tree(int *a, int len)
{
    for (int i = 0; i < len; ++i) {
        int j = i;
        while (a[j] < a[(j-1)/2])
        {
            int t = a[j];
            a[j] = a[(j-1)/2];
            a[(j-1)/2] = t;
            j = (j - 1) / 2;
        }
    }
}

int select_min(int *a, int len)
{
    swap(a, 0, len-1);
    int i = 0;
    len--;
    while(i*2+1 < len)
    {
        int min;
        int left = i*2+1;
        if(left+1 < len)
        {
            int right = left+1;
            if(a[right] < a[left])
                min = right;
            else
                min = left;
        }
        else
            min = left;
        if(a[min] < a[i])
        {
            swap(a, min, i);
            i = min;
        }
        else
            break;
    }
    return a[len];
}

void insert(int *a, int num, int len)
{
    a[len] = num;
    while(a[len] < a[(len-1)/2])
    {
        swap(a, len, (len-1)/2);
        len = (len-1)/2;
    }
}

int main()
{
    int a[] = {10, 20, 30};
    int len = 3;
    int sum = 0;

    create_tree(a, len);
    while(len > 1)
    {
        int min_1 = select_min(a, len);
        len--;
        int min_2 = select_min(a, len);
        len--;
        sum = sum + min_1 +min_2;
        insert(a, min_1+min_2, len);
        len++;
    }

    cout<< sum<< endl;

}


