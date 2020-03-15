#include <iostream>

int main()
{
    int currVal = 0, var = 0;
    if(std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> var)
        {
            if(currVal == var)
            {
                ++cnt;
            } else
            {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = var;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}