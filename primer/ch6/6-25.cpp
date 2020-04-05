//
// Created by baul on 4/4/20.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "请给main函数输入至少两个实参。" << endl;
        return -1;
    }
    string ss;
    for(int i = 1; i < argc; ++i) // 从第二个元素开始
    {
        ss += string(argv[i]);
    }
    cout << ss << endl;
    return 0;
}