//
// Created by baul on 3/23/20.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    string ss;
    vector<string> text;
    while(getline(cin, ss))
    {
        text.push_back(ss);
    }

    for(auto it = text.begin();
        it != text.end() && !it->empty(); ++it) // 读取第一行字符串
    {
        if(!it->empty())
        {
            for(auto &c : *it) // 将第一行的所有字符转换为大写形式.
            {
                c = toupper(c);
            }
        } else
        {
            cout << "Empty line." << endl;
        }

    }

    cout << *(text.begin()) << endl; // 输出第一行字符串。
    return 0;
}