//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

int main()
{
    int data;
    vector<int> ivec;
    while(cin >> data)
    {
        ivec.push_back(data);
    }

    // function1
    cout << "相邻元素相加：　" << endl;
    if(!ivec.empty())
    {
        for(decltype(ivec.size()) i = 0; i < ivec.size(); ++i)
        {
            std::cout << ivec[i] + ivec[++i] << std::endl; // ++i为当前遍历元素的下一个元素，这样每次for循环跳过两个元素。
        }
    } else
    {
        cerr << "Empty vector!" << endl;
    }

    //function2
    cout << "首尾元素相加：　" << endl;
    if(!ivec.empty())
    {
        for(decltype(ivec.size()) i = 0; i < ivec.size()/2; ++i) // 增长至一半
        {
            std::cout << ivec[i] + ivec[ivec.size() - 1 - i] << std::endl; // ivec[ivec.size() - 1 - i]为倒数第i个元素.
        }
    } else
    {
        cerr << "Empty vector!" << endl;
    }
}
