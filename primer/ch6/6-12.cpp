//
// Created by baul on 4/2/20.
//

#include <iostream>

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 10, b = 5;
    std::cout << "交换前: a= " << a << ", b= " << b << std::endl;
    swap(a, b);
    std::cout << "交换后: a= " << a << ", b= " << b << std::endl;
    return 0;
}
