//
// Created by baul on 3/15/20.
//
#include "Sales_item.h"

#include <iostream>

int main()
{
    Sales_item saledBook1, saledBook2;
    std::cin >> saledBook1 >> saledBook2;
    if(saledBook1.isbn() == saledBook2.isbn())
    {
        std::cout << saledBook1 + saledBook2 << std::endl;
    }
    return 0;
}