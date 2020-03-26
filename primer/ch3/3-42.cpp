//
// Created by baul on 3/26/20.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int arr[10];
    auto arr_it1 = begin(arr);
    auto arr_it2 = end(arr);
    vector<int> ivec = {0, 1, 2, 3, 4, 5};
    auto ivec_it1 = ivec.begin();
    auto ivec_it2 = ivec.end();
    while(arr_it1 != arr_it2 && ivec_it1 != ivec_it2)
    {
        *arr_it1 = *ivec_it1;
        ++arr_it1; ++ivec_it1;
    }
    for(auto i : arr)
    {
        cout << i << endl;
    }
    return 0;
}
