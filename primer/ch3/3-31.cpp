//
// Created by baul on 3/24/20.
//

#include <iostream>

int main()
{
    int ia[10];
    std::cout << "ia = [";
    for(size_t i = 0; i < 10; ++i)
    {
        ia[i] = i;
        std::cout << ia[i];
        if(i != 9)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]." << std::endl;

    return 0;
}