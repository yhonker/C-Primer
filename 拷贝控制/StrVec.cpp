//
// Created by yh on 2021/8/20.
//

#include "StrVec.h"

StrVec::StrVec(StrVec &&s) noexcept :elements(s.elements),first_free(s.first_free),cap(s.cap){
    s.elements = s.first_free = s.cap = nullptr;
}


void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if(elements) {
        for(auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
}

StrVec::~StrVec() { free();}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() : 1;
    //拷贝方式
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
    /*移动方式
     auto first = alloc.allocate(newcapacity);
     //移动元素
     auto last = uninitialized_copy(make_move_iterator(begin()), make_iterator(end()), first);
     free();
     elements = first;
     first_free = last;
     cap = elements + newcapacity;
     */
}

void StrVec::reserve(size_t n) {
    if(n<=capacity()) return;
    auto first = alloc.allocate(n);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + n;
}

void StrVec::resize(size_t count) {
    if(count > size()){
        if(count > capacity()) reserve(count * 2);
        for(size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, string(" "));
    } else if(count < size()){
        while(first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

StrVec::StrVec(initializer_list<string> il) {
    range_initialize(il.begin(), il.end());
}

void StrVec::range_initialize(const std::string *first, const std::string *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}
