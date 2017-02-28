#ifndef EX_7_05_H
#define EX_7_05_H

#include <string>

struct Person
{
    std::string name;
    std::string address;

    const std::string &getName() const { return name; }
    const std::string &getAddress() const { return address; }
};

#endif