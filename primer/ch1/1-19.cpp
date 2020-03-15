#include <iostream>

int main()
{
    int smallerNum = 0.0, biggerNum = 0.0;
    std::cout << "Please input two integers, e.g. 1 6: ";
    std::cin >> smallerNum >> biggerNum;
    std::cout << std::endl;
    // 交换两个数
    if(biggerNum < smallerNum)
    {
         biggerNum = smallerNum + biggerNum;
         smallerNum = biggerNum - smallerNum;
         biggerNum = biggerNum - smallerNum;
    }
    // 递增打印
    std::cout << "All numbers of " << smallerNum << " to " << biggerNum
    << " are [";
    while (smallerNum <= biggerNum)
    {
        std::cout << smallerNum;
        if(smallerNum != biggerNum)
        {
            std::cout << ", ";
        }
        ++smallerNum;
    }
    std::cout << "]." << std::endl;
    return 0;
}