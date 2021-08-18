//
// Created by yh on 2021/8/16.
//

#ifndef CPPTRAIN_OTHER_H
#define CPPTRAIN_OTHER_H
#include <bits/stdc++.h>
using namespace std;

class Other {

};

struct NoDtor{
    NoDtor() = default;
    ~NoDtor() = delete;
};

//错误：NoDtor的析构函数被阻止
//NoDtor nd;

//正确：但我们不能delete p
NoDtor *p = new NoDtor();

#endif //CPPTRAIN_OTHER_H
