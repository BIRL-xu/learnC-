//
// Created by baul on 3/29/20.
//
#include <iostream>

using namespace std;
int main()
{
    std::cout << "char occupies " << sizeof(char) << " bytes." << endl;
    std::cout << "unsigned char occupies " << sizeof(unsigned char) << " bytes." << endl;

    std::cout << "short occupies " << sizeof(short) << " bytes." << endl;
    std::cout << "int occupies " << sizeof(int) << " bytes." << endl;
    std::cout << "unsigned occupies " << sizeof(unsigned) << " bytes." << endl;
    std::cout << "long occupies " << sizeof(long) << " bytes." << endl;
    std::cout << "long long occupies " << sizeof(long long) << " bytes." << endl;

    std::cout << "float occupies " << sizeof(float) << " bytes." << endl;
    std::cout << "double occupies " << sizeof(double) << " bytes." << endl;
    std::cout << "long double occupies " << sizeof(long double) << " bytes." << endl;
    return 0;
}