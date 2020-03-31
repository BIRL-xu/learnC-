//
// Created by baul on 3/30/20.
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    string lastWord, maxWord;
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
            if(cnt > maxCnt)
            {
                maxWord = lastWord;
                maxCnt = cnt;
            }
        } else
        {
            lastWord = word;
            cnt = 1;
        }
    }
    cout << "重复出现次数最多的单词是：　" << maxWord
    << "; 重复出现次数是　" << maxCnt << "　次。" << endl;
    return 0;
}
