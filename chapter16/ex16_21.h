#ifndef EX_16_21_H_
#define EX_16_21_H_

#include <iostream>

class DebugDelete
{
  public:
    DebugDelete(std::ostream &o = std::cerr) : os(o) {}

    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

  private:
    std::ostream &os;
};

#endif // !DEBUGDELETE_H_
