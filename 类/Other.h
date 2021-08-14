//
// Created by honker on 2021/8/14.
//

#ifndef CPPTRAIN_OTHER_H
#define CPPTRAIN_OTHER_H
#include <bits/stdc++.h>
using namespace std;

class Other {

};

//构造函数的初始值有时必不可少
class ConstRef{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

/*错误:ci和ri必须被初始化
ConstRef::ConstRef(int ii) {
    i = ii;
    ci = ii;
    ri = i;
}
*/

//正确
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}


//成员初始化顺序
class X{
    int i;
    int j;
public:
    //未定义的：i在j之前被初始化
    //X(int val):j(val),i(j){}
    //正确
    X(int val):j(val),i(val){}
};

//默认构造函数的作用
class Nodefault{
public:
    Nodefault(const string &s);
};

class A{
public:
    Nodefault my_mem;
};
//错误：不能为A合成构造函数
//A a;

struct B{
    //错误：b_memeber没有初始值
    //B(){}
    Nodefault b_member;
};
#endif //CPPTRAIN_OTHER_H
