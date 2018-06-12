/*
 * Created by dawn on 18-6-5.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string int2string(int val)
{
    string result = "";
    if(val < 0)
    {
        val = -val;
        result += "-";
    }
    while(val >= 10)
    {
        int temp = val % 10;
        char int1 = (char)((val/10) + int('0'));
        if(val/10 == 0 && temp < 10)
            char int1 = (char)(temp);
        result += int1;
        cout<< result<<" ";
        val = temp;
    }
    return result;
}

int main()
{
    int val = 101;
    string result = int2string(val);
    cout<< result<< endl;
}