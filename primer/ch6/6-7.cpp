//
// Created by baul on 4/2/20.
//

#include <iostream>

int fact()
{
    static int num = 0;

    return num++;
}
int main()
{
    for(int i = 0; i < 10; ++i)
    {
        std::cout << fact()  << std::endl;
    }
    return 0;
}
