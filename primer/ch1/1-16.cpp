#include <iostream>

int main()
{
    int sum = 0, var = 0;
    std::cout << "Please input a series of integers: ";
    while(std::cin >> var)
    {
        sum += var;
    }
    std::cout << "Sum is " << sum << std::endl;

    return 0;
}