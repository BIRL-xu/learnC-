//
// Created by baul on 3/30/20.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch)
    {
        if('a' == ch)
        {
            ++aCnt;
        }
        if('e' == ch)
        {
           ++eCnt;
        }
        if('i' == ch)
        {
            ++iCnt;
        }
        if('o' == ch)
        {
            ++oCnt;
        }
        if('u' == ch)
        {
            ++uCnt;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;
    return 0;
}