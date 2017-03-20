#ifndef EX_13_36_H_
#define EX_13_36_H_

#include <set>

#include "ex13_34.h"

class Folder
{
    friend class Message;
    friend void swap(Folder &, Folder &);

  public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

  private:
    std::set<Message *> msgs;

    void add_to_Message(const Folder &);
    void remove_from_Message();
    void addMsg(Message *);
    void remMsg(Message *);
};

#endif