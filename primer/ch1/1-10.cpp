#include <iostream>

int main()
{
    int var = 10;
    std::cout << "Print all numbers of 10 to 0 : ";
    while (var >= 0)
    {
        std::cout << var;
        if(var)
        {
            std::cout << ", ";
        }
        --var;
    }
    std::cout << "." << std::endl;
    return 0;
}