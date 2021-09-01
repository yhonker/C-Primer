//
// Created by yh on 2021/8/18.
//

#include "Message.h"

void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

Message::Message(const Message &rhs):contents(rhs.contents),\
folders(rhs.folders){
add_to_Folders(rhs);
}
void Message::remove_from_Folders(){
    for(auto it:folders){
        it->remMsg(this);
    }
}
Message &Message::operator=(const Message &rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message(){
    remove_from_Folders();
}

void Message::move_Folders(Message *m){
    folders = std::move(m->folders);
    for(auto f : folders){
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void swap(Message &lhs, Message &rhs){
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

Message &Message::operator=(Message &&rhs) {
    if(this != &rhs){
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}
