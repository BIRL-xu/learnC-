//
// Created by baul on 4/10/20.
//

#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

ifstream &readFile(ifstream &input)
{
    input.open("test.txt", ios::in);
    string line;
    vector<string> lines;
    while(getline(input, line))
    {
        lines.push_back(line);
    }

    return input;
}
