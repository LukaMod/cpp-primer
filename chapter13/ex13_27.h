#ifndef EX_13_27_H_
#define EX_13_27_H_

#include <string>
#include <iostream>

class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    HasPtr &operator=(const HasPtr &rhs);
    ~HasPtr();

  private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    this->~HasPtr();
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
        std::cout << "free" << std::endl;
    }
    std::cout << "~HasPtr()" << std::endl;
}

#endif