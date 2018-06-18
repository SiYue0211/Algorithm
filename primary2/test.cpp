/*
 * Created by dawn on 18-6-5.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main()
{
    int a[5] = {1, 3, 2, 8, 0};
    sort(a, a+5, compare);
    for(int i = 0; i< 5; i++)
        cout<< a[i]<< " ";
    cout<< endl;
}