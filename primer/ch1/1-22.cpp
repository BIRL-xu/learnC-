//
// Created by baul on 3/15/20.
//
#include "Sales_item.h"

#include <iostream>

int main()
{
    Sales_item currentSaledBook, varSaledBook;
    if(std::cin >> currentSaledBook)
    {
        while(std::cin >> varSaledBook)
        {
            if (currentSaledBook.isbn() == varSaledBook.isbn())
            {
                currentSaledBook += varSaledBook;
            } else
            {
                std::cout << currentSaledBook << std::endl;
                currentSaledBook = varSaledBook;
            }
        }
        std::cout << currentSaledBook << std::endl;
    }

    return 0;
}
