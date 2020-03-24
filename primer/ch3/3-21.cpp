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
    cout << "v1的大小为: " << v1.size() << endl;
    cout << "v1中的元素为：　";
    for(auto iter = v1.cbegin(); iter != v1.cend(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<int> v2(10); // 10个元素值都为０的容器。
    cout << "v2的大小为: " << v2.size() << endl;
    cout << "v2中的元素为：　";
    for(auto iter = v2.cbegin(); iter != v2.cend(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<int> v3(10, 42); // 10个元素值都为42的容器。
    cout << "v3的大小为: " << v3.size() << endl;
    cout << "v3中的元素为：　";
    for(auto iter = v3.cbegin(); iter != v3.cend(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<int> v4{10}; // １个元素值为10的容器。
    cout << "v4的大小为: " << v4.size() << endl;
    cout << "v4中的元素为：　";
    for(auto iter = v4.cbegin(); iter != v4.cend(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<int> v5{10, 42}; // 2个元素值为10和42的容器。
    cout << "v5的大小为: " << v5.size() << endl;
    cout << "v5中的元素为：　";
    for(auto iter = v5.cbegin(); iter != v5.cend(); ++iter)
    {
        std::cout << *iter << endl;
    }

    vector<string> v6{10}; // 10个默认初始化的元素。
    cout << "v6的大小为: " << v6.size() << endl;
    cout << "v6中的元素为：　";
    for(auto iter = v6.cbegin(); iter != v6.cend(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<string> v7{10, "hi"}; // 10个元素值都为hi的容器。
    cout << "v7的大小为: " << v7.size() << endl;
    cout << "v7中的元素为：　";
    for(auto iter = v7.cbegin(); iter != v7.cend(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
