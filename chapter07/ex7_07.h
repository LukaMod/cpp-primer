#ifndef EX_7_09_H
#define EX_7_09_H

#include <string>
using std::string;
using std::istream;
using std::ostream;

struct Person
{
    string name;
    string address;

    const string &getName() const { return name; }
    const string &getAddress() const { return address; }
};

istream &read(istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

ostream &print(ostream &os, const Person &item)
{
    os << item.getName() << " " << item.getAddress();
    return os;
}

#endif