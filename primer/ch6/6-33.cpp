//
// Created by baul on 4/4/20.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ivec)
{
    static decltype(ivec.size()) num = 0;
    if(num != ivec.size())
    {
        cout << ivec[num++] << endl;
        print(ivec);
    }
}

int factorial(int val)
{
    if(val > 1)
    {
        return factorial(val - 1)*val;
    }
    return 1;
}

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4};
    print(ivec);
    cout << factorial(10);
    return 0;
}
