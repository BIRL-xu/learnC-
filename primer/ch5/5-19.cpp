//
// Created by baul on 3/31/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    do{
        cout << "Please enter two string: ";
        cin >> s1 >> s2;
        if(s1.size() <= s2.size())
        {
            cout << s1 << endl;
        } else
        {
            cout << s2 << endl;
        }
    }while (s1 != "q");
    return 0;
}