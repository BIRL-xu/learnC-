//
// Created by baul on 3/26/20.
//
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(arr + 2, arr + 6);
    for(auto i : ivec)
    {
        cout << i << endl;
    }
    return 0;
}