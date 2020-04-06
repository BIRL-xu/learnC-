//
// Created by baul on 4/6/20.
//

#include <iostream>
#include "7-11.h"

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    if(units_sold)
    {
        return revenue / units_sold;
    }
    return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << ", " << item.units_sold << ", "
       << item.revenue << ", " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}


int main()
{

    Sales_data total;
    Sales_data book1("三体");
    Sales_data book2("三体", 1000, 46.5);
    Sales_data book3(std::cin);

    return 0;
}