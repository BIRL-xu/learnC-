//
// Created by baul on 3/27/20.
//

#include <iostream>
#include <vector>
int main()
{
    int a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    int b = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);

    std::cout << "12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 = " << a << std::endl;
    std::cout << "((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) = " << b << std::endl;

    int a1 = -30 * 3 + 21 / 5;
    int b1 = -30 + 3 * 21 / 5;
    int c = 30 / 3 * 21 % 5;
    int d = -30 / 3 * 21 % 4;
    std::cout << "-30 * 3 + 21 / 5 = " << a1 << std::endl;
    std::cout << "-30 + 3 * 21 / 5 = " << b1 << std::endl;
    std::cout << "30 / 3 * 21 % 5 = " << c << std::endl;
    std::cout << "-30 / 3 * 21 % 4 = " << d << std::endl;

    std::vector<int> ivec = {0, 1, 2, 3};
    auto it = ivec.begin();
    std::cout << ++*it << std::endl;
    return 0;
}