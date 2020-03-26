//
// Created by baul on 3/26/20.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "Hello1";
    const char ca1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    const char ca2[] = {'H', 'e', 'l', 'l', 'o', '1', '\0'};
    if(str1 == str2)
    {
        cout << str1 << " = " << str2 << endl;
    } else if(str1 < str2)
    {
        cout << str1 << " < " << str2 << endl;
    } else
    {
        cout << str1 << " > " << str2 << endl;
    }

    if(!strcmp(ca1, ca2))
    {
        cout << "ca1 = ca2" << endl;
    } else if(strcmp(ca1, ca2) < 0)
    {
        cout << "ca1 < ca2" << endl;
    } else
    {
        cout << "ca1 > ca2" << endl;
    }

    return 0;
}