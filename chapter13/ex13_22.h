#ifndef EX_13_22_H_
#define EX_13_22_H_

#include <string>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  HasPtr &operator=(const HasPtr &rhs)
  {
    auto newp = std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }
  ~HasPtr() { delete ps; }
private:
  std::string *ps;
  int i;
};

#endif