//
// Created by baul on 3/29/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> ivec = {1, 23, 5,2, 6, 5, 64,99, 100};
    for(auto e : ivec)
    {
        cout << "Number " << e << " --> " << ((e%2==0) ? e : 2*e) << endl;
    }

    string s = "word";
    string p1 = s + s[s.size()-1] == "s" ? "" : "s";
    cout << p1;
    return 0;
}
