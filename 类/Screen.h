//
// Created by honker on 2021/8/12.
//

#ifndef CPPTRAIN_SCREEN_H
#define CPPTRAIN_SCREEN_H
#include <bits/stdc++.h>
#include "Window_mgr.h"
using namespace std;

class Screen {
public:
    typedef string::size_type pos;//using pos = string::size_type;  类型成员放在开头
    Screen() = default;
    //隐式内联
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd,c){}
    //显示内联
    inline char get(pos r, pos c) const;
    //能在定义时被设为内联                     //内联函数定义必须放在头文件中
    Screen &move(pos r, pos c);

    Screen &set(char c);
    Screen &set(pos r, pos col, char ch);

    //可变数据类型
    mutable size_t access_ctr;

    //基于const的重载
    Screen &display(ostream &os){//为Screen时调用
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const{//为const Screen时调用
        do_display(os);
        return *this;
    }

    friend class Window_mgr;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void some_member() const;
    void do_display(ostream &os) const{os << contents;}
};


char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

#endif //CPPTRAIN_SCREEN_H
