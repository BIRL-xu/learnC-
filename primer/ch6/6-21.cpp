//
// Created by baul on 4/4/20.
//

#include <iostream>

const int compare(const int a, const int *const p)
{
    if(a > *p)
    {
        return a;
    }
    return *p;
}

int main()
{
    int a = 10, b = 11;
    int *p = &b;
    std::cout << compare(a, p) << std::endl;
    return 0;
}