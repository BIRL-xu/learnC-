//
// Created by baul on 3/29/20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> gradeList = {42, 80, 98, 55, 63, 74, 22, 70};
    for(auto grade : gradeList)
    {
        string finalGrade = (grade > 90) ? "high pass"
                : (grade < 60) ? "fail"
                    : (grade < 75) ? "low pass" : "pass";
        cout << grade << (" is " + finalGrade) << endl;
    }
    cout << endl;
    for(auto grade : gradeList)
    {
        if(grade > 90)
        {
            cout << grade << " is high pass." << endl;
        } else if(grade < 60)
        {
            cout << grade << " is fail." << endl;
        } else if(grade < 75)
        {
            cout << grade << " is low pass." << endl;
        } else
        {
            cout << grade << " pass." << endl;
        }
    }

}

