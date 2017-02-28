#ifndef EX_7_15_H
#define EX_7_15_H

#include <string>
using std::string;
using std::istream;
using std::ostream;

struct Person
{
    Person() = default;
    Person(const string &sname) : name(sname) {}
    Person(const string &sname, const string &saddr) : name(sname), address(saddr) {}
    Person(istream &is) { read(is, *this); }

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