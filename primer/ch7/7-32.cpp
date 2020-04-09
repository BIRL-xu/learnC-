//
// Created by baul on 4/7/20.
//
#include "7-32.h"
#include <iostream>

using namespace std;

Window_mgr::Window_mgr() : screens({(24, 80, ' ')}) {

}
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

int main()
{
    return 0;
}