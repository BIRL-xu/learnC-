//
// Created by baul on 3/23/20.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    for(decltype(ivec.size()) i = 1; i <= 10; ++i)
    {
        ivec.push_back(i);
    }
    cout << "原始元素: " << endl;
    for(auto e : ivec)
    {
        cout << e << " ";
    }
    cout << endl << "两倍元素：　";
    for(auto it = ivec.begin(); it != ivec.end(); ++it)
    {
        *it *= *it;
        cout << *it << " ";
    }

    return 0;
}
