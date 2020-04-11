//
// Created by baul on 4/10/20.
//
#include <iostream>
#include <string>
class A{
public:
    A(std::string a){}
//    A &combine(A a){}
//    A &combine(A &a){}
    A &combine(const A &a) const{}
};

int main()
{
    std::string str = "hello";
    std::string str1 = "world";
    A test(str);
    test.combine(str1);
}