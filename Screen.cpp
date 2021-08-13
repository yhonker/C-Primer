//
// Created by honker on 2021/8/12.
//

#include "Screen.h"

void Screen::some_member() const {
    ++access_ctr;//const 对象中的可变数据类型也可以修改
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(Screen::pos r, Screen::pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}


