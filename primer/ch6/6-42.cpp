//
// Created by baul on 4/5/20.
//
#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word,
                               const string &ending = "s")
{
    return (ctr > 1) ? word +ending : word;
}

int main()
{
    string s1 = "success";
    string s2 = "failure";
    cout << make_plural(1, s1) << endl;
    cout << make_plural(2, s2) << endl;
    return 0;
}
