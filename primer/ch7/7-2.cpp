//
// Created by baul on 4/6/20.
//

#include <iostream>
#include "7-2.h"

Sales_data & Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{

    return 0;
}