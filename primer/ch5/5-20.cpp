//
// Created by baul on 3/31/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, lastStr;
    while(cin >> str)
    {
        if(lastStr == str)
        {
            lastStr = " ";
            break;
        }
        lastStr = str;
    }
    if(" " == lastStr)
    {
        cout << "单词" << str << "重复出现。" << endl;
    } else
    {
        cout << "没有任何单词是连续重复出现的。" << endl;
    }
    return 0;
}
