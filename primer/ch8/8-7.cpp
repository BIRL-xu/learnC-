//
// Created by baul on 4/11/20.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Sales_data{

    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    double agv_price() const
    {
     if(units_sold)
     {
         return revenue/units_sold;
     }
     return 0;
    }
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.agv_price();
    return os;
}

int main(int argc, char *argv[])
{
    Sales_data total;
    if(argc < 3)
    {
        cout << "Usage: ./8-7 file1 file2" << endl;
        return -1;
    }
    ifstream input(argv[1]);
    ofstream out(argv[2], ofstream::app); //　将输出追加到文件末尾，不会覆盖已有内容。
    if(input)
    {
        if (read(input, total)) // 形参是基类istream对象的引用，传入的是派生类ifstream的对象。
        {
            Sales_data trans;
            while(read(input, trans))
            {
                if(total.isbn() == trans.isbn())
                {
                    total.combine(trans);
                } else
                {
                    print(out, total) << endl; // 形参是基类ostream对象的引用，传入的是派生类ofstream的对象。
                    total = trans;
                }
            }
            print(out, total) << endl;
        } else
        {
            cerr << "No data?!" << endl;
        }
    } else
    {
        cerr << "Open file failed." << endl;
    }

    return 0;
}
