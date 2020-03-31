//
// Created by baul on 3/31/20.
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> smallVec = {0, 1, 1, 2};
    vector<int> bigVec = {0, 1, 1, 2, 3, 5, 8};

    if(smallVec.size() > bigVec.size())
    {
        auto tempVec = smallVec;
        smallVec = bigVec;
        bigVec = tempVec;
    }
    auto it1 = smallVec.begin();
    auto end1 = smallVec.end();
    auto it2 = bigVec.begin();
    auto end2 = bigVec.end();
    while(it1 != end1 && *it1 == *it2)
    {
        ++it1;
        ++it2;
    }
    if(it1 == end1)
    {
        cout << "小vector是大vector的前缀" << endl;
    } else
    {
        cout << "小vector不是大vector的前缀" << endl;
    }

    return 0;
}