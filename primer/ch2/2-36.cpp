//
// Created by baul on 3/21/20.
//

#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a; // c是int型
    decltype((b)) d= a; // d是int型引用
    decltype(a = b) e = a;
    std::cout << "e = " << e << std::endl;
    ++c;
    ++d;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    return 0;
}