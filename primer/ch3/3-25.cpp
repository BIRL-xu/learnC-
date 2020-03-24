//
// Created by baul on 3/24/20.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int grade = 0;
    vector<unsigned int> scores(11, 0);
    auto beg = scores.begin();
    auto end = scores.end();
    while (cin >> grade)
    {
        if(grade <= 100)
        {
            beg+= grade/10;  // 迭代器前进到该成绩所属分数段
            if(beg != end)
            {
                ++(*beg);
            }
        }
        beg = scores.begin(); // 重置迭代器，保证每次都是从起点开始移动。
    }

   for(auto it = scores.cbegin(); it != scores.cend(); ++it)
   {
       cout << *it << " ";
   }
    return 0;
}