#include "ex13_49_Message.h"

#include "ex13_49_Folder.h"

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::Message(Message &&m) noexcept : contents(std::move(m.contents)), folders(std::move(m.folders))
{
    m.remove_from_Folders;
    m.folders.clear();
}

Message &Message::operator=(Message &&rhs) noexcept
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        folders = std::move(rhs.folders);
        rhs.folders.clear();
    }
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &)
{
    for (auto &f : folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto &f : folders)
        f->remMsg(this);
}

void Message::addFolder(Folder *f)
{
    folders.insert(f);
}

void Message::remFolder(Folder *f)
{
    folders.erase(f);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}
