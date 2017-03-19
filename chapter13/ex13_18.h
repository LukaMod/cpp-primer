#ifndef EX_13_18_H_
#define EX_13_18_H_

#include <string>

class Employee
{
  public:
    Employee();
    Employee(const std::string &);

  private:
    std::string name;
    int id;
    static int increase;
};

#endif