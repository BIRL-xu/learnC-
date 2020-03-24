//
// Created by baul on 3/24/20.
//

#include <iostream>
#include <vector>
int main()
{
    int ia[10];
    int ib[10];
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

    // 数组拷贝赋值
    std::cout << "ib = [";
    for(size_t j = 0; j < 10; ++j)
    {
        ib[j] = ia[j];
        std::cout << ia[j];
        if(j != 9)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]." << std::endl;

    // 初始化vector.
    std::vector<int> ivec(10);
    unsigned int k = 0;
    std::cout << "ivec = [";
    for(auto &e : ivec)
    {
        e = k;
        ++k;
        std::cout << e << " ";
    }
    std::cout << "]." << std::endl;
    // vector赋值
    std::vector<int> ivec1 = ivec;
    std::cout << "ivec1 = [";
    for(auto &e : ivec1)
    {
        std::cout << e << " ";
    }
    std::cout << "]." << std::endl;
    std::vector<int> ivec2(ivec);
    std::cout << "ivec2 = [";
    for(auto &e : ivec2)
    {
        std::cout << e << " ";
    }
    std::cout << "]." << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *p = &arr[2];
    std::cout << "p = " << p << "->" << *p << std::endl;
    int j = p[1];
    std::cout << "p = " << p << "->" << j << std::endl;
    int m = p[-2];
    std::cout << "p = " << p << "->" << m << std::endl;
    return 0;
}