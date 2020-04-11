//
// Created by baul on 4/10/20.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

istream &read(istream &is)
{
    string word;
    while(!is.eof() && is >> word)
    {
        cout << word << endl;
    }

    is.clear();
    return is;
}

int main()
{
    istringstream strstm("hello world");
    read(strstm); // 形参是istream基；类对象的引用，传入的实参是istringstream对象。
    return 0;
}