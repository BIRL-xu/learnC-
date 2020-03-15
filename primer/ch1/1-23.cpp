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
        int cnt = 1;
        while(std::cin >> varSaledBook)
        {
            if (currentSaledBook.isbn() == varSaledBook.isbn())
            {
                ++cnt;
            } else
            {
                std::cout << currentSaledBook.isbn() << " has " << cnt << " sale records." <<  std::endl;
                currentSaledBook = varSaledBook;
                cnt = 1;
            }
        }
        std::cout << currentSaledBook.isbn() << " has " << cnt << " sale records." <<  std::endl;
    }

    return 0;
}
