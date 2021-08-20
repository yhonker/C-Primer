//
// Created by yh on 2021/8/16.
//有普通指针成员，需要自定义析构函数，拷贝构造函数，拷贝赋值运算符。

#ifndef CPPTRAIN_HASPTR_H
#define CPPTRAIN_HASPTR_H

#include <bits/stdc++.h>
using namespace std;

//错误版本
class HasPtr1 {
public:
    HasPtr1(const string &s = string()):ps(new string(s)), i(0){}
    ~HasPtr1(){delete ps;}
    //类定义错误：HasPtr需要一个拷贝构造函数和一个拷贝赋值运算符
private:
    string *ps;
    int i;
};

//类值版本
class HasPtr2{
public:
    HasPtr2(const string &s = string()):ps(new string(s)), i(0){}
    //对ps指向的string，每个HasPtr对象都有自己的拷贝
    HasPtr2(const HasPtr2 &p):ps(new string(*p.ps)), i(p.i){}
    HasPtr2 &operator=(const HasPtr2 &rhs);
    //swap版本拷贝赋值运算符
    /*
     HasPtr& operator=(HasPtr rhs)={
        swap(*this, rhs);
        return *this;
     }
     */
    ~HasPtr2(){delete ps;}
    friend void swap(HasPtr2 &lhs, HasPtr2 &rhs);

private:
    string *ps;
    int i;
};
inline
void swap(HasPtr2 &lhs, HasPtr2& rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


//指针行为版本--定义一个使用引用计数的类
class HasPtr3{
public:
    //构造函数分配新的string和新的计算器，将计算器置1
    HasPtr3(const string &s = string()):ps(new string(s)), i(0), use(new size_t(1)){}
    //拷贝构造函数拷贝所有三个数据成员，并递增计算器
    HasPtr3(const HasPtr3 &p):ps(p.ps), i(p.i), use(p.use){++*use;}
    HasPtr3 &operator=(const HasPtr3 &rhs);
    ~HasPtr3();
private:
    string *ps;
    int i;
    size_t *use;    //用来记录有多少个对象共享*ps的成员
};

#endif //CPPTRAIN_HASPTR_H