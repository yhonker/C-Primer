//
// Created by yh on 2021/8/16.
//

#include "HasPtr.h"

//错误：ps会被delete两次
HasPtr f(HasPtr hp){
    HasPtr ret = hp;
    return ret;
}

//错误：p和q都指向无效内存！
/*
HasPtr p("some values");
f(p);
HasPtr q(p);
*/
