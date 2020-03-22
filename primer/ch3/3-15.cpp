//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::string;
using std::vector;
int main()
{
    string s;
    vector<string> ivec;
    while(cin >> s)
    {
        ivec.push_back(s);
    }
    return 0;
}