//
// Created by baul on 4/10/20.
//

#include <iostream>
#include <string>

using namespace std;

istream &read(istream &is)
{
    string word;
    while(!is.eof() && is >> word)
    {
        cout << word << endl;
    }

    is.clear();
    return is;
}

int main()
{
    read(cin);
    return 0;
}