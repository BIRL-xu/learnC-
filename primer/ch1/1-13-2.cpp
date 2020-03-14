#include <iostream>

int main()
{

    std::cout << "Print all numbers of 10 to 0 : ";
    for(int var = 10; var >= 0; --var)
    {
        std::cout << var;
        if(var)
        {
            std::cout << ", ";
        }
    }
    std::cout << "." << std::endl;
    return 0;
}