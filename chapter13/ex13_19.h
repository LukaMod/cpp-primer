#ifndef EX_13_19_H_
#define EX_13_19_H_

#include <string>

class Employee
{
  public:
    Employee();
    Employee(const std::string &);
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

  private:
    std::string name;
    int id;
    static int increase;
};

#endif