//
// Created by honker on 2021/9/1.
//

#include "Folder.h"

void Folder::add_to_Messages(const Folder &f){
    for(auto m:f.messages)
        m->addFlr(this);
}

void Folder::remove_from_Messages(){
    for(auto m : messages)
        m->rmFlr(this);
}

Folder &Folder::operator=(const Folder &rhs){
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

void swap(Folder &lhs, Folder &rhs){
    using std::swap;
    lhs.remove_from_Messages();//可以访问私有成员?
    rhs.remove_from_Messages();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}