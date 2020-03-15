//
// Created by baul on 3/15/20.
//
#include "Sales_item.h"

#include <iostream>

int main()
{
    Sales_item saledBook;
    while(std::cin >> saledBook)
    {
        std::cout << saledBook << std::endl;
    }
    return 0;
}