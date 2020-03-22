//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string combinedStr;
    while(cin >> str)
    {
        combinedStr += str + " ";
    }
    cout << combinedStr << endl;
    return 0;
}
