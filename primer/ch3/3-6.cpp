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
    for(auto &c : str)
    {
        c = 'X';
    }

    cout << "新字符串: " << str << endl;
}
