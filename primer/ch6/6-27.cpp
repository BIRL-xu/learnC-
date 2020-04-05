//
// Created by baul on 4/4/20.
//

#include <iostream>
#include <initializer_list>

using namespace std;

int getSum(initializer_list<int> &il)
{
    int sum = 0;
    for(auto &e : il)
    {
        sum += e;
    }
    return sum;
}

int main()
{
    initializer_list<int> is = {0 ,2, 3, 4, 5};
    cout << getSum(is) << endl;

    return 0;
}
