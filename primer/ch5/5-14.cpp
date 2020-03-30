//
// Created by baul on 3/30/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    string lastWord;
    unsigned int maxCnt = 0;
    unsigned int cnt = 1;
    while(cin >> word)
    {
        if(lastWord.empty())
        {
            lastWord = word;
            continue;
        }
        if(lastWord == word)
        {
            ++cnt;
        } else
        {
            maxCnt = cnt;
            cnt = 1;
        }

    }
    return 0;
}
