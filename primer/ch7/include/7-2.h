//
// Created by baul on 4/6/20.
//

#ifndef CH6_7_2_H
#define CH6_7_2_H
#include <string>

struct Sales_data{
    std::string isbn() const {}
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CH6_7_2_H
