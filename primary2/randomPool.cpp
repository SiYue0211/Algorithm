/*
 * Created by dawn on 18-6-8.
 * 题目描述：设计RandomPool结构
 *         设计一种结构， 在该结构中有如下三个功能：
 *         insert(key)： 将某个key加入到该结构， 做到不重复加入。
 *         delete(key)： 将原本在结构中的某个key移除。 getRandom()：
 *         等概率随机返回结构中的任何一个key。
 * 要求：Insert、 delete和getRandom方法的时间复杂度都是O(1)
 *
 * 思路：hash_map可以保证不重复加入
*/
#include <iostream>
#include <hash_map>
#include <string>
using namespace std;
using namespace __gnu_cxx;


class randPool{
public:
    int size;
    hash_map<int, int> keyIndexMap;
    hash_map<int, int> valueIndexMap;
    randPool():size(0){}
    bool insert(int);
    bool del(int);
    int getRand();
};


bool randPool::insert(int key) {
    if(keyIndexMap.find(key) != keyIndexMap.end())
        return false;
    keyIndexMap[key] = size;
    valueIndexMap[size++] = key;
    return true;
}

bool randPool::del(int key) {
    if(keyIndexMap.find(key) == keyIndexMap.end())
        return false;
    int del_index = keyIndexMap[key];
    size--;
    int key_last = valueIndexMap[size];
    keyIndexMap.erase(key);
    keyIndexMap.erase(key_last);
    valueIndexMap.erase(del_index);
    valueIndexMap.erase(size);
    keyIndexMap[key_last] = del_index;
    valueIndexMap[del_index] = key_last;
    return true;
}

int randPool::getRand() {
    int ran= rand() % size;
    return valueIndexMap[ran];
}




int main()
{
    randPool rand;
    rand.insert(10);
    cout << rand.getRand()<< endl;

}












