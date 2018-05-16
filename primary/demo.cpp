//
// Created by root on 18-5-9.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "some strung";
    for(auto it=s.begin(); it!=s.end()&& !isspace(*it);++it)
        *it = toupper(*it);
    for(auto i:s)
        cout<<i;
}