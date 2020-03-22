//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <vector>

using std::cin;
using std::vector;
int main()
{
    int data;
    vector<int> ivec;
    while(cin >> data)
    {
        ivec.push_back(data);
    }
    return 0;
}