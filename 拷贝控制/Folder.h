//
// Created by honker on 2021/9/1.
//

#ifndef CPPTRAIN_FOLDER_H
#define CPPTRAIN_FOLDER_H
#include "Message.h"

class Folder{

    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &rhs):messages(rhs.messages){ add_to_Messages(rhs);}
    Folder &operator=(const Folder &rhs);
    ~Folder(){ remove_from_Messages();}

private:
    set<Message*> messages;
    void addMsg(Message *m){ messages.insert(m);}
    void remMsg(Message *m){ messages.erase(m);}//给Message对象调用,不能主动添加Message
    void add_to_Messages(const Folder &f);
    void remove_from_Messages();

};



#endif //CPPTRAIN_FOLDER_H
