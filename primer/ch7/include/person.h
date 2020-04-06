//
// Created by baul on 4/6/20.
//

#ifndef CH6_7_4_H
#define CH6_7_4_H

#include <iostream>
#include <string>

class Person{
    friend std::istream &read(std::istream &is, Person &someone);
    friend std::ostream &print(std::ostream &os, const Person &someone);
public:
    Person() = default;
    Person(const std::string &id, const std::string& addr) :
           name(id), address(addr){}
    Person(std::istream &is)
    {
        is >> name >> address;
    }

    std::string getName() const {return name;} // 返回值不能是普通引用类型，因为常量函数体内的变量被隐式声明为了常量；
//    const std::string &getName() const {return name;} // 正确
    std::string getAddress() const {return address;}
//    const std::string &getAddress() const {return address;} // 正确
private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &someone);
std::ostream &print(std::ostream &os, const Person &someone);

#endif //CH6_7_4_H
