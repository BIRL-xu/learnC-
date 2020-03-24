//
// Created by baul on 3/24/20.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    constexpr unsigned int size = 5;
    int ia[size];
    int ib[size];
    for( size_t index = 0; index < size; ++index)
    {
        ia[index] = index;
        ib[index] = index;
    }
    // 改变其中几个元素使其不相等
    ib[2] = -1;
    // 输入数组a，只读入每行的前size个数据。
    cout << "ia: ";
    for(auto e : ia)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "ib: ";
    for(auto e : ib)
    {
        cout << e << " ";
    }
    cout << endl;

    // 读入vector
    vector<int> ivec1;
    vector<int> ivec2;
    for( size_t index = 0; index < size; ++index)
    {
        ivec1.push_back(index);
        ivec2.push_back(index);
    }

    // 改变其中几个元素使其不相等
    ivec1[0] = 999;
    cout << "ivec1: ";
    for(auto e : ivec1)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "ivec2: ";
    for(auto e : ivec2)
    {
        cout << e << " ";
    }
    cout << endl;
    // 比较两个数组是否相等
    auto iaBeg = begin(ia);
    auto ibBeg = begin(ib);
    while(iaBeg != end(ia) && ibBeg != end(ib))
    {
        if(*iaBeg != *ibBeg)
        {
            break;
        }
        ++iaBeg;
        ++ibBeg;
    }
    if(iaBeg != end(ia) && ibBeg != end(ib))
    {
        cout << "两个数组不相等." << endl;
    } else
    {
        cout << "两个数组相等." << endl;
    }

    // 比较两个vector是否相等
    if(ivec1 == ivec2)
    {
        cout << "两个vector对象相等。" << endl;
    } else
    {
        cout << "两个vector对象不相等。" << endl;
    }

    return 0;
}