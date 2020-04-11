//
// Created by baul on 4/11/20.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "Usage: ./8-11 file" << endl;
    }
    ifstream input(argv[1]);
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(input, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    // verify
    for(auto person: people)
    {
        cout << person.name << person.phones[0] << endl;
    }
}