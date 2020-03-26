//
// Created by baul on 3/26/20.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char ca1[] = "hello"; // size = 6(包含空字符)
    const char ca2[] = "world"; // size = 6。
    char ca3[10]; // 6+6 = 12，但只需要一个空字符，所以定义大小为11即可。
    strcpy(ca3, ca1);
    strcat(ca3, ca2);
    for(char c : ca3)
    {
        cout << c << "|";
    }
    return 0;
}