//
// Created by baul on 4/6/20.
//

#ifndef CH6_7_23_H
#define CH6_7_23_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    Window_mgr();
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen{
public:
    typedef unsigned pos;
    friend void Window_mgr::clear(ScreenIndex);

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' '){}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}

    char get() const{
        return contents[cursor];
    }

    inline char get(pos r, pos c) const{
        pos row = r * width;
        return contents[row+c];
    }

    Screen &move(pos r, pos c){
        pos row = r * width;
        cursor = row + c;
        return *this;
    }

    inline Screen &set(char c)
    {
        contents[cursor] = c;
        return *this;
    }

    void someMember(){++access_ctr;}

    Screen &display(std::ostream &os)
    {
        do_display(os); // this指针被隐式转换为指向常量的指针，隐式转换的常量属性只在do_display内有效；
        return *this;   // 解引用后得到非常量对象
    }
    // 重载为常量函数，返回类型只能是常量，this指针被隐式转换为指向常量的指针
    const Screen &display(std::ostream &os) const
    {
        do_display(os); // this指针被隐式转换为了常量指针
        return *this;  // 在该函数内，this指针始终指向常量，所以解引用后还是常量。
    }
private:
    // 常量函数
    void do_display(std::ostream &os) const
    {
        os << contents;
    }

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable unsigned access_ctr;

};
#endif //CH6_7_23_H
