#include "ex13_36.h"

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Message(f);
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

Folder::~Folder()
{
    remove_from_Message();
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto &m : f.msgs)
        m->folders.insert(this);
}

void Folder::remove_from_Message()
{
    for (auto &m : msgs)
        m->folders.erase(this);
}

void Folder::addMsg(Message *m)
{
    msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
    msgs.erase(m);
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();
    swap(lhs.msgs, rhs.msgs);
    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}
