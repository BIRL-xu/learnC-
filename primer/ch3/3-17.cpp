//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string ss;
    while(cin >> ss)
    {
        for(auto &c : ss)   // 通过引用修改ss。
        {
            c = toupper(c); // 将小写字母转换为大写字母。
        }
        cout << ss << endl;
    }
    return 0;
}
