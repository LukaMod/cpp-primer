#ifndef EX_7_05_H_
#define EX_7_05_H_

#include <string>

struct Person
{
    std::string name;
    std::string address;

    const std::string &getName() const { return name; }
    const std::string &getAddress() const { return address; }
};

#endif