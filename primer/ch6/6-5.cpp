//
// Created by baul on 4/2/20.
//

#include <iostream>

int getAbs(int a)
{
    int b = (a < 0) ? -a : a;
    return b;
}

int main()
{
    int i = 0;
    std::cout << "请输入一个整数：　";
    std::cin >> i;
    std::cout << i << " 的绝对值是 " << getAbs(i) << std::endl;
    return 0;
}