//
// Created by baul on 4/6/20.
//

#ifndef CH6_7_23_H
#define CH6_7_23_H

#include <string>

class Screen{
public:
    typedef unsigned pos;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' '){}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}

    char get() const{
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const{
        pos row = r * width;
        return contents[ros+c];
    }

    Screen &move(pos r, pos c){
        pos ros = r * width;
        cursor = row + c;
        return *this;
    }
    void someMember(){++access_ctr;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable unsigned access_ctr;

};
#endif //CH6_7_23_H
