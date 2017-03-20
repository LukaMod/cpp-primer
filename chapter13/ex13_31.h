#ifndef EX_13_31_H_
#define EX_13_31_H_

#include <string>
#include <iostream>

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(HasPtr &, HasPtr &);

  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }
    ~HasPtr() { delete ps; }
  private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    std::cout << "swap(HasPtr&, HasPtr&)" << std::endl;
}

inline bool operator<(HasPtr &lhs, HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

#endif