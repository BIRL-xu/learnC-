//
// Created by baul on 3/22/20.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str("hello world");
    cout << "原始字符串: " << str << endl;

    decltype(str.size()) sz = 0;
    while(sz < str.size())
    {
        str[sz] = 'X';
        ++sz;
    }
    cout << "新字符串: " << str << endl;

    for(sz; sz < str.size(); ++sz)
    {
        str[sz] = 'X';
    }
    cout << "新字符串: " << str << endl;
}
