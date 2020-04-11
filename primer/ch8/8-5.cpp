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
    string word;
    vector<string> words;
    while(input >> word)
    {
        words.push_back(word);
    }

    return input;
}

int main()
{
    return 0;
}