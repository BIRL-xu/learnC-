//
// Created by baul on 4/6/20.
//
#include "person.h"


std::istream &read(std::istream &is, Person &someone)
{
    is >> someone.name >> someone.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &someone)
{
   os << someone.getName() << ", " << someone.getAddress();
   return os;
}


int main()
{

    return 0;
}