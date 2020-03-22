//
// Created by baul on 3/22/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    // function1: check if the str1 is equal to str2.
    if(str1 == str2)
    {
        cout << "The strings are equal." << endl;
    } else
    {
        if(str1 > str2)
        {
            cout << str1 << endl;
        } else
        {
            cout << str2 << endl;
        }
    }

    // function2: check if the length of the str1 is equal to that of the str2.
    if(str1.size() == str2.size())
    {
        cout << "The size of str1(str2) is " << str1.size() << endl;
    } else
    {
        if(str1.size() > str2.size())
        {
            cout << str1 << endl;
        } else
        {
            cout << str2 << endl;
        }
    }

}
