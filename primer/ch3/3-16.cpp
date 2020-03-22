//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v1; // 空vector
    std::cout << "v1的大小为: " << v1.size() << endl;
    std::cout << "v1中的元素为：　";
    for(auto i : v1)
    {
        std::cout << i << endl;
    }

    vector<int> v2(10); // 10个元素值都为０的容器。
    std::cout << "v2的大小为: " << v2.size() << endl;
    std::cout << "v2中的元素为：　";
    for(auto i : v2)
    {
        std::cout << i << endl;
    }

    vector<int> v3(10, 42); // 10个元素值都为42的容器。
    std::cout << "v3的大小为: " << v3.size() << endl;
    std::cout << "v3中的元素为：　";
    for(auto i : v3)
    {
        std::cout << i << endl;
    }

    vector<int> v4{10}; // １个元素值为10的容器。
    std::cout << "v4的大小为: " << v4.size() << endl;
    std::cout << "v4中的元素为：　";
    for(auto i : v4)
    {
        std::cout << i << endl;
    }

    vector<int> v5{10, 42}; // 2个元素值为10和42的容器。
    std::cout << "v5的大小为: " << v5.size() << endl;
    std::cout << "v5中的元素为：　";
    for(auto i : v5)
    {
        std::cout << i << endl;
    }

    vector<string> v6{10}; // 10个默认初始化的元素。
    std::cout << "v6的大小为: " << v6.size() << endl;
    std::cout << "v6中的元素为：　";
    for(auto i : v6)
    {
        std::cout << i << endl;
    }

    vector<string> v7{10, "hi"}; // 10个元素值都为hi的容器。
    std::cout << "v7的大小为: " << v7.size() << endl;
    std::cout << "v7中的元素为：　";
    for(auto i : v7)
    {
        std::cout << i << endl;
    }
    return 0;
}
