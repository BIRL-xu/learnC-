//
// Created by baul on 3/21/20.
//

#include <iostream>

int main()
{
    const int i = 42;
    auto j = i; // int类型,可修改j的值。
    j = 50;
    const auto &k = i; // const int类型的引用,不可通过k修改i的值。
    // k = 10; // 错误
    auto *p = &i; // const int*类型,不可通过p修改i的值。
    //*p = 0; // 错误
    p = nullptr; // 合法

    const auto j2 = i, &k2 = i; // j2 是const int类型, k2是const int& 类型。
   // j2 = -1; // 错误
   // k2 = 10;　// 错误
    return 0;
}