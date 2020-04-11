//
// Created by baul on 4/11/20.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Usage: ./8-10 file" << endl;
    }
    ifstream input(argv[1]);
    string line;
    vector<string> lines;
    while(getline(input, line))
    {
        lines.push_back(line);
    }

    for(auto line : lines)
    {
        istringstream strs(line); // 将一行string绑定到istringstream对象。
        string word;
        while(strs >> word) // 从istringstream对象读取单个string。
        {
            cout << word << endl;
        }
    }
    return 0;
}
