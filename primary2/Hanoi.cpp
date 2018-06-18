/*
 * Created by dawn on 18-6-18.
 * 汉诺塔问题
*/

#include <iostream>
#include <string>
using namespace std;

void hanoi(int n, string l, string r, string m){
    if(n == 1)
        cout<< "move from " + l + " to " + r<< endl;
    else{
        hanoi(n-1, l, m, r);
        cout<< "move from " + l + " to " + r<< endl;
        hanoi(n-1, m, r, l);
    }
}

int main(){
    hanoi(3, "left", "right", "middle");
}