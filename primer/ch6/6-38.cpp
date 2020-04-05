//
// Created by baul on 4/5/20.
//

#include <iostream>
#include <iterator>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype((odd)) arrPtr(int i)
{
    return (i % 2) ? odd : even;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "请给main函数传入一个整数参数" << std::endl;
        return -1;
    }

    auto result = arrPtr(static_cast<int>(*argv[1])); // 返回int*，不能使用范围for循环。
    for(size_t i = 0; i < (end(odd) - begin(odd)); ++i)
    {
        std::cout << result[i] << endl;
    }
    return 0;
}