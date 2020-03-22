//
// Created by baul on 3/22/20.
//

#include <iostream>
#include <string>

using std::string ;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string line;
    getline(cin, line);
    cout << line << endl;

    string word;
    while(cin >> word)
    {
        cout << word << endl;
    }
    return 0;
}