//
// Created by baul on 4/4/20.
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
bool hasUpperChar(const string &s)
{
    for(auto &c : s)
    {
        if(c > 'A' && c < 'Z')
        {
            return true;
        }
    }

    return false;
}

void exchangeToLower(string &s)
{
    for(auto &c : s)
    {
        c = tolower(c);
    }
}

int main()
{
    string s = "Hello World";
    cout << s << "包含大写字母吗？--" << (hasUpperChar(s) ? "Yes" : "No") << endl;

    exchangeToLower(s);
    cout << "转换为小写形式后为: " <<  s << endl;
    return 0;
}