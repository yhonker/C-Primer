//
// Created by yh on 2021/8/16.
//

#include "HasPtr.h"

//错误：ps会被delete两次
/*
HasPtr f(HasPtr hp){
    HasPtr ret = hp;
    return ret;
}
*/


//错误：p和q都指向无效内存！
/*
HasPtr p("some values");
f(p);
HasPtr q(p);
*/



//正确的拷贝赋值赋值运算符
HasPtr2 &HasPtr2::operator=(const HasPtr2 &rhs) {
    auto newp = new string(*(rhs.ps));    //拷贝底层string
    delete ps;  //释放旧内存
    ps = newp;
    i = rhs.i;
    return *this;
}

//错误的拷贝赋值运算符
/*
HasPtr2 &HasPtr2::operator=(const HasPtr2 &rhs) {
    delete ps;  //释放旧内存

    //如果rhs 和 *this 是同一个对象，我们就将从已释放的内存中拷贝数据！
    ps = new string(*(rhs.ps));

    i = rhs.i;
    return *this;
}

*/
HasPtr3::~HasPtr3() {
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr3 &HasPtr3::operator=(const HasPtr3 &rhs) {
    ++*rhs.use;
    if(--*use == 0){    //然后递减本对象的引用计数
        delete ps;      //如果没用其他用户
        delete use;     //释放本对象分配的成员
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}
