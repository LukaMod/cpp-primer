#ifndef EX_14_35_H_
#define EX_14_35_H_

#include <iostream>
#include <string>

class InputString
{
  public:
    InputString(std::istream &i = std::cin) : is(i) {}
    std::string operator()() const
    {
        std::string s;
        std::getline(is, s);
        return is ? s : std::string();
    }

  private:
    std::istream &is;
};

#endif