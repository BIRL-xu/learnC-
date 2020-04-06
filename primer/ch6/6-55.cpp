//
// Created by baul on 4/5/20.
//

#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}

int product(int a, int b)
{
    return (a * b);
}

int divide(int a, int b)
{
    if (b)
    {
        return (a / b);
    }
    return 0;
}


int main()
{
    // 使用typedef和decltype
    typedef int(*pf1)(int ,int);
    vector<pf1> pfVec1;
    typedef decltype(add) *pf2;
    vector<pf2> pfVec2;
// 使用using
    using pf3 = int(*)(int, int);
    vector<pf3> pfVec3;

    pfVec1.push_back(add);
    pfVec1.push_back(subtraction);
    pfVec1.push_back(product);
    pfVec1.push_back(divide);

    pfVec2.push_back(add);
    pfVec2.push_back(subtraction);
    pfVec2.push_back(product);
    pfVec2.push_back(divide);

    pfVec3.push_back(add);
    pfVec3.push_back(subtraction);
    pfVec3.push_back(product);
    pfVec3.push_back(divide);

    int a = 1, b = 2;
    for(auto &pf : pfVec1)
    {
        cout << pf(a, b) << endl; // 使用函数指针指针同一类型的函数，能够便捷地进行调用。
    }

    for(auto &pf : pfVec2)
    {
        cout << pf(a, b) << endl;
    }

    for(auto &pf : pfVec3)
    {
        cout << pf(a, b) << endl;
    }
    return 0;
}