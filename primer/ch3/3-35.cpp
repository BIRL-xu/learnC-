//
// Created by baul on 3/24/20.
//

#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << "原始数组：　";
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // 利用指针置0
    auto begIt = begin(arr);
    auto endIt = end(arr);
    while (begIt != endIt)
    {
        *begIt = 0;
        ++begIt;
    }
    cout << "数组置0：　";
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}