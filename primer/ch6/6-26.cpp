//
// Created by baul on 4/4/20.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "输入错误" << endl;
        return -1;
    }

    for(int i = 1; i < argc; ++i) // 从第二个元素开始
    {
        cout << argv[i] << endl;
    }

    return 0;
}