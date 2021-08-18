//
// Created by yh on 2021/8/16.
//定义删除的函数，即阻止拷贝，阻止赋值等

#ifndef CPPTRAIN_NOCOPY_H
#define CPPTRAIN_NOCOPY_H
#include <bits/stdc++.h>
using namespace std;

class NoCopy {
public:
    NoCopy() = default;
    //阻止拷贝
    NoCopy(const NoCopy&) = delete;
    //阻止赋值
    NoCopy operator=(const NoCopy&) = delete;
    ~NoCopy() = default;
};


#endif //CPPTRAIN_NOCOPY_H
