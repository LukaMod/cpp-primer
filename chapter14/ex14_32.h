#ifndef EX_14_32_H_
#define EX_14_32_H_

#include "ex14_26_StrBlobPtr.h"

class StrBlobPtr_ptr
{
  public:
    StrBlobPtr_ptr() : p(nullptr) {}
    StrBlobPtr_ptr(StrBlobPtr *ptr) : p(ptr) {}
    StrBlobPtr &operator*() const;
    StrBlobPtr *operator->() const;

  private:
    StrBlobPtr *p;
};

#endif