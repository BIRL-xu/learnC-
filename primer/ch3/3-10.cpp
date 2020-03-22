//
// Created by baul on 3/22/20.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string str, nonpunctStr;
    cin >> str;

    for(auto &c : str)
    {
        if(ispunct(c))
        {
            continue;
        }
        nonpunctStr += string(1, c); // 将非标点符号的字符拼接成新字符串。
    }

    cout << nonpunctStr << endl;
     const string s = "hello";
     for(auto &c : s)
     {
        // c = 'X'; // 错误： c是const char的引用。
     }
    return 0;
}
