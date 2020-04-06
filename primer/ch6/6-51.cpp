//
// Created by baul on 4/5/20.
//

#include <iostream>

using namespace std;

void f()
{
    cout << "f()" << endl;
}

void f(int)
{
    cout << "f(int)" << endl;
}

void f(int, int)
{
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "f(double, double = 3.14)" << endl;
}

int main()
{
//    f(2.56, 42); // 编译器自动警报二义性
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}