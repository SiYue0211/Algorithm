/*
 * Created by dawn on 18-6-13.
*/
#include <iostream>
#include <hash_map>
#include <vector>
using namespace std;
using namespace __gnu_cxx;

class UnionFindSet{
public:
    hash_map<int, int> fatherMap;
    hash_map<int, int> sizeMap;
    void makeSets(vector<int>);
    int findHead(int);
    bool isSameSet(int a, int b);
    void unionSet(int a, int b);
};

void UnionFindSet::makeSets(vector<int> list) {
    for(auto i: list)
    {
        fatherMap[i] = i;
        sizeMap[i] =  1;
    }
}

int UnionFindSet::findHead(int a) {
    int father = fatherMap[a];
    if(father != a)
        father = findHead(father);
    fatherMap[a] = father;
    return father;
}

bool UnionFindSet::isSameSet(int a, int b) {
    return findHead(a) == findHead(b);
}

void UnionFindSet::unionSet(int a, int b) {
    int aHead = findHead(a);
    int bHead = findHead(b);
    if(aHead != bHead)
    {
        int aSetSize = sizeMap[aHead];
        int bSetSize = sizeMap[bHead];
        if(aSetSize <= bSetSize)
        {
            fatherMap[aHead] = bHead;
            sizeMap[bHead] = aSetSize + bSetSize;
        }
        else
        {
            fatherMap[bHead] = aHead;
            sizeMap[aHead] = aSetSize + bSetSize;
        }
    }
}

int main()
{
    vector<int> list = {1, 2, 3, 4, 5};
    UnionFindSet set;
    set.makeSets(list);
    cout<< set.findHead(2)<< endl;
    cout<< set.isSameSet(1, 2)<< endl;
    set.unionSet(1, 2);
    cout<< set.isSameSet(1, 2)<< endl;

}
