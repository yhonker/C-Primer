//
// Created by yh on 2021/8/20.
//

#ifndef CPPTRAIN_STRVEC_H
#define CPPTRAIN_STRVEC_H
#include <bits/stdc++.h>
using namespace std;
class StrVec {
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){ }

    //接收initializer_list<string>的构造函数
    StrVec(initializer_list<string> il);
    void range_initialize(const std::string *first, const std::string *last);

    //移动构造函数
    StrVec(StrVec&&) noexcept;

    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&&) noexcept;//移动赋值运算符
    ~StrVec();
    void push_back(const string&);
    size_t size() const { return first_free - elements;}
    size_t capacity() const{ return cap - elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}
    void reserve(size_t );
    void resize(size_t count);

private:
    static allocator<string> alloc;//
    void chk_n_alloc(){if(size() == capacity()) reallocate();}
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};



#endif //CPPTRAIN_STRVEC_H
