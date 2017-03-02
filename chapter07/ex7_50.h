#ifndef EX_7_50_H_
#define EX_7_50_H_

#include <string>

class Person
{
    friend std::istream &read(std::istream &, Person &);

  public:
    Person() = default;
    Person(const std::string &sname) : name(sname) {}
    Person(const std::string &sname, const std::string &saddr) : name(sname), address(saddr) {}
    explicit Person(std::istream &is) { read(is, *this); }

    const std::string &getName() const { return name; }
    const std::string &getAddress() const { return address; }

  private:
    std::string name;
    std::string address;
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