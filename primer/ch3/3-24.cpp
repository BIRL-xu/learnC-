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
    auto beg = ivec.cbegin();
    auto end = ivec.cend();
    for(beg; beg < end; ++beg)
    {
        cout << (*beg) + (*(++beg)) << endl;
    }

    //function2
    beg = ivec.cbegin();
    end = ivec.cend();
    auto mid = beg + (end - beg) / 2;
    cout << "首尾元素相加：　" << endl;
    for(beg; beg < mid; ++beg)
    {
        cout << *beg + *(--end) << endl;
    }

}
