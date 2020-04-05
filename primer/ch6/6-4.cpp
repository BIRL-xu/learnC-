//
// Created by baul on 4/2/20.
//
#include <iostream>
#include <cmath>
int fact()
{
    int a = 0, ret = 1;
    std::cout << "请输入一个整数：　";
    std::cin >> a;
    while(abs(a) > 1)
    {
        ret *=a--;
    }

    return ret;
}

int main()
{
    std::cout << fact() << std::endl;
    return 0;
}