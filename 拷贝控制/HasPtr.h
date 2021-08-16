//
// Created by yh on 2021/8/16.
//有普通指针成员，需要自定义析构函数，拷贝构造函数，拷贝赋值运算符。

#ifndef CPPTRAIN_HASPTR_H
#define CPPTRAIN_HASPTR_H

#include <bits/stdc++.h>
using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()):ps(new string(s)), i(0){}
    ~HasPtr(){delete ps;}
    //类定义错误：HasPtr需要一个拷贝构造函数和一个拷贝赋值运算符
private:
    string *ps;
    int i;
};


#endif //CPPTRAIN_HASPTR_H
