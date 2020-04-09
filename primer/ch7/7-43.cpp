//
// Created by baul on 4/9/20.
//

#include <iostream>
#include <vector>

class NoDefault{
public:
    NoDefault(int a) : i(a){}

private:
    int i;
};

class C{
public:
    C() : obj(-1){}
//    C(){} // 错误，要求显示初始化成员obj。
private:
    NoDefault obj;
};

int main()
{
    std::vector<NoDefault> vec(10, NoDefault(5));
    C c;
    return 0;
}