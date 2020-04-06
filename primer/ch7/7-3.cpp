//
// Created by baul on 4/6/20.
//

#include <iostream>
#include "7-3.h"

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

int main()
{
    Sales_data total;
    if(std::cin >> total.bookNo >> total.revenue >> total.units_sold)
    {
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.revenue >> trans.units_sold)
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            } else
            {
                std::cout << total.isbn() << ", " << total.revenue << ", " << total.avg_price() << std::endl;
                total = trans;
            }
        }

        std::cout << total.isbn() << ", " << total.revenue << ", " << total.avg_price() << std::endl;
    } else
    {
        std::cerr << "Nodata>!" << std::endl;
    }

    return 0;
}