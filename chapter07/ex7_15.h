#ifndef EX_7_15_H_
#define EX_7_15_H_

#include <string>

struct Person
{
    Person() = default;
    Person(const std::string &sname) : name(sname) {}
    Person(const std::string &sname, const std::string &saddr) : name(sname), address(saddr) {}
    Person(std::istream &is) { read(is, *this); }

    std::string name;
    std::string address;

    const std::string &getName() const { return name; }
    const std::string &getAddress() const { return address; }
};

std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item)
{
    os << item.getName() << " " << item.getAddress();
    return os;
}

#endif