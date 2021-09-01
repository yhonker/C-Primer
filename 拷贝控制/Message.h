//
// Created by yh on 2021/8/18.
//

#ifndef CPPTRAIN_MESSAGE_H
#define CPPTRAIN_MESSAGE_H
#include <bits/stdc++.h>
#include "Folder.h"
using namespace std;
class Folder;

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const string &s = ""):contents(s) { }
    Message(Message &&m):contents(std::moce(m.contents)){move_Folders(&m);}//移动构造函数
    Message(const Message &rhs);
    Message &operator=(const Message &rhs);
    Message &operator=(Message &&rhs);//移动赋值运算符
    ~Message();
    void save(Folder &f);
    void remove(Folder &f);

private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message &m);
    void remove_from_Folders();
    void addFlr(Folder *f){ folders.insert(f);}
    void rmFlr(Folder *f){ folders.erase(f);}
    void move_Folders(Message *m);//从Message移动Folder指针
};





#endif //CPPTRAIN_MESSAGE_H
