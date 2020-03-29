//
// Created by baul on 3/29/20.
//

#include <iostream>

using namespace std;

int main()
{
    int x[10]; int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl; // 输出数组大小10。
    // 在32位计算机上输出１：　因为sizeof(p)是int型指针所占空间大小，为４个字节; sizeof(*p)为int型数据占４个字节，因此输出为１．
    // 在64为计算机上输出２: 因为sizeof(p)是int型指针所占空间大小，为8个字节; sizeof(*p)为int型数据占４个字节，因此输出为１．
    cout << sizeof(p)/sizeof(*p) << endl;
    return 0;
}